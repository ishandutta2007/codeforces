#include <bits/stdc++.h>

using namespace std;
const int c=8002;
int t[c], lk[c], ki[c], n, pos=1, db, mini;
long long sum;
bool sz[c][c], v[c];
bool f(int a, int b) {return 2*(sz[a][pos]-sz[b][pos])+sz[a][b]>0;}
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0);
    cin >> n;
    for (int i=1; i<=n; i++) for (int j=4; j<=n; j+=4) {
        char c; cin >> c;
        int x=c-'0';
        if (x>10) x-=7;
        for (int k=0; k<4; k++) sz[i][j-k]=(x%2), x/=2, ki[i]+=sz[i][j-k];
    }
    for (int i=1; i<=n; i++) t[i]=i;
    for (int i=1; i<=n; i++) if (ki[i]<ki[pos]) pos=i;
    db=ki[pos], mini=n+1;
    sort(t+1, t+n+1, f);
    for (int i=n; i>=1; i--) if (sz[t[n]][t[i]]) mini=i;
    for (int i=1; i<=n-db-1; i++) for (int j=1; j<=n; j++) if (sz[t[i]][t[j]]) lk[i]=j;
    for (int i=n-db; i<=n; i++) for (int j=1; j<=n-db-1; j++) if (sz[t[i]][t[j]]) lk[i]=j;
    for (int i=1; i<=n; i++) for (int j=1; j<=n; j++) if (i!=j) {
        if (sz[t[i]][t[j]]) sum++;
        else if (sz[t[lk[i]]][t[j]] || (sz[t[i]][t[n]] && sz[t[n]][t[j]])) sum+=2;
        else if (j<mini) sum+=614*n;
        else sum+=3;
    }
    cout << sum << "\n";
    return 0;
}