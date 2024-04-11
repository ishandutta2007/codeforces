#include <bits/stdc++.h>

using namespace std;
const int c=3005;
bool v[c][c];
int n, m, l[c][c], r[c][c], bl[c][c], fen[c];
vector<int> cl[c];
long long ans;
int lsb(int a) {
    return (a & -a);
}
void add(int a, int ert) {
    while (a<=m) {
        fen[a]+=ert;
        a+=lsb(a);
    }
}
int ask(int a) {
    int ans=0;
    while (a) {
        ans+=fen[a];
        a-=lsb(a);
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            char c;
            cin >> c;
            v[i][j]=(c=='z');
        }
        for (int j=1; j<=m; j++) {
            l[i][j]=(v[i][j] ? l[i][j-1] : j);
        }
        r[i][m+1]=m+1;
        for (int j=m; j>=1; j--) {
            r[i][j]=(v[i][j] ? r[i][j+1] : j);
        }
    }
    for (int i=1; i<=m; i++) {
        bl[n+1][i]=i;
    }
    for (int i=n; i>=1; i--) {
        for (int j=1; j<=m; j++) {
            bl[i][j]=(v[i][j] ? bl[i+1][j-1] : j);
        }
    }
    for (int sum=2; sum<=n+m; sum++) {
        int pos=max(1, sum-m);
        for (int a=max(1, sum-m); a<=min(n, sum-1); a++) {
            int b=sum-a;
            add(b, 1);
            cl[max(l[a][b], bl[a][b])].push_back(b);
            for (auto x:cl[b]) {
                add(x, -1);
            }
            cl[b].clear();
            //cout << "ertek " << a << " " << b << " " << ask(r[a][b]-1) << "\n";
            ans+=ask(r[a][b]-1);
        }
        for (auto x:cl[max(0, sum-n-1)]) {
            add(x, -1);
        }
        cl[max(0, sum-n-1)].clear();
    }
    cout << ans << "\n";
    return 0;
}
/*
4 4
zzzz
zzz.
.z..
zzzz
*/