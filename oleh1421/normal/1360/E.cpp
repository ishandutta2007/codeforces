//#pragma GCC optimize("O2")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=1010;
bool used[N][N];
int a[N][N];
void dfs(int x,int y){
    if (!a[x][y] || used[x][y]) return;
    used[x][y]=true;
    dfs(x-1,y);
    dfs(x,y-1);
}
int n,m;
void solve(){
    int n;cin>>n;
    for (int i=0;i<=n+1;i++){
        for (int j=0;j<=n+1;j++){
            a[i][j]=used[i][j]=0;
        }
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            char c;cin>>c;
            a[i][j]=(c-'0');
        }
    }
    for (int i=1;i<=n;i++){
        dfs(i,n);
    }
    for (int i=1;i<=n;i++){
        dfs(n,i);
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            if (a[i][j] && !used[i][j]){
                cout<<"NO\n";
                return;
            }
        }
    }
    cout<<"YES\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}
/*
4
0100
1110
0101
0111
*/