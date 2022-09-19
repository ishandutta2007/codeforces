#include <bits/stdc++.h>

using namespace std;
const int c=102;
int ans[c], n, db[c][32];
vector<int> sz[c];
vector<pair<int, int> > s[c];
void ask(int a, int b) {
    if (b<=0) return;
    cout.flush() << "? " << a << " " << b << "\n";
    int c=b-a+1;
    for (int i=1; i<=n; i++) for (int j=1; j<=30; j++) db[i][j]=0;
    for (int i=1; i<=(c+1)*c/2; i++) {
        string s; cin >> s;
        int si=s.size();
        for (int j=0; j<si; j++) {
            int x=s[j]-'a'+1;
            db[si][x]++;
            //db[si][s[i]-'a'+1]++;
        }
    }
    for (int i=2; i<=(c+2)/2; i++) {
        int x=0, y=0;
        for (int j=1; j<=30; j++) if (db[i-1][j]*i!=db[i][j]*(i-1)) x=j;
        for (int j=1; j<=c; j++) db[j][x]-=min({i-1, j, c-j+1});
        for (int j=1; j<=30; j++) if (db[i-1][j]*i!=db[i][j]*(i-1)) y=j;
        for (int j=1; j<=c; j++) db[j][y]-=min({i-1, j, c-j+1});
        int p=a+i-2, q=b-p+a;
        sz[p].push_back(q), sz[q].push_back(p), s[p].push_back({x, y}), s[q].push_back({x, y});
    }
    for (int i=1; i<=30; i++) if (db[1][i]) ans[(a+b)/2]=i;
}
void dfs(int a) {
    for (int i=0; i<sz[a].size(); i++) {
        int x=sz[a][i], p=s[a][i].first, q=s[a][i].second;
        if (!ans[x]) {
            if (ans[a]==p) ans[x]=q;
            else ans[x]=p;
            dfs(x);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    if (n%2) ask(1, n), ask(1, n/2+1), ask(n/2+1, n-1);
    else ask(1, n), ask(1, (n+1)/2), ask((n+1)/2, n);
    for (int i=1; i<=n; i++) if (ans[i]) dfs(i);
    cout << "! ";
    for (int i=1; i<=n; i++) { char c='a'-1+ans[i]; cout << c;}
    return 0;
}
/*
2 az a z a a z az
*/