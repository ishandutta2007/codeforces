#include <bits/stdc++.h>

using namespace std;
const int c=2002;
int w, n, m;
bitset<c> b[c], s, kesz;
queue<pair<int, int> > q;
vector<pair<int, int> > ans;
void add(int a) {
    if (kesz[a]) {
        return;
    }
    for (int i=1; i<=n; i++) {
        s[i]=1;
    }
    for (int i=1; i<=m; i++) {
        if (b[i][a]) {
            s&=b[i];
        }
    }
    int x=0;
    for (int i=1; i<=n; i++) {
        if (!kesz[i] && s[i] && i!=a) {
            x=i;
        }
    }
    if (x) {
        //cout << "jo " << a << " " << x << "\n";
        for (int i=1; i<=m; i++) {
            b[i][a]=0;
            if (b[i].count()==1) {
                b[i]=0;
            }
        }
        kesz[a]=1;
        q.push({a, x});
    }
    s=0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> m;
        for (int i=1; i<=m; i++) {
            for (int j=1; j<=n; j++) {
                char c;
                cin >> c;
                b[i][j]=(c=='1');
            }
            if (b[i].count()==1) {
                b[i]=0;
            }
        }
        for (int i=1; i<=n; i++) {
            add(i);
        }
        while (q.size()>0) {
            int a=q.front().first, b=q.front().second;
            q.pop();
            kesz[a]=1;
            ans.push_back({a, b});
            add(b);
        }
        if (ans.size()==n-1) {
            cout << "YES\n";
            for (auto x:ans) {
                cout << x.first << " " << x.second << "\n";
            }
        } else {
            cout << "NO\n";
        }
        for (int i=1; i<=m; i++) {
            b[i]=0;
        }
        kesz=0;
        ans.clear();
    }
    return 0;
}
/*
1
2 0
*/