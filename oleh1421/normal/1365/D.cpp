//#pragma GCC optimize("O2")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
typedef long double ld;
#define double ld
using namespace std;
const int N=1010;
char a[N][N];
bool used[N][N];
void dfs(int x,int y){
    if (used[x][y]) return;
    if (a[x][y]=='#') return;
    used[x][y]=true;
    dfs(x,y-1);
    dfs(x,y+1);
    dfs(x-1,y);
    dfs(x+1,y);
}
void solve()
{
    int n,m;cin>>n>>m;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            cin>>a[i][j];
            used[i][j]=false;
        }
    }
//    if (a[n][m]=='B'){
//        cout<<"No\n";
//        return;
//    }
    for (int i=1;i<=n;i++){
        a[i][0]='#';
        a[i][m+1]='#';
    }
    for (int j=1;j<=m;j++){
        a[0][j]='#';
        a[n+1][j]='#';
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            if (a[i][j]!='B') continue;
            if (a[i-1][j]=='G' || a[i][j-1]=='G' || a[i+1][j]=='G' || a[i][j+1]=='G'){
                cout<<"No\n";
                return;
            }
            if (a[i-1][j]!='B') a[i-1][j]='#';
            if (a[i+1][j]!='B') a[i+1][j]='#';
            if (a[i][j-1]!='B') a[i][j-1]='#';
            if (a[i][j+1]!='B') a[i][j+1]='#';
        }
    }
    dfs(n,m);
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            if (!used[i][j] && a[i][j]=='G'){
                cout<<"No\n";
                return;
            }
        }
    }
    cout<<"Yes\n";

}
int main()
{

//    freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}