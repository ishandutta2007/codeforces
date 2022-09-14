#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
#define endl '\n'
//#define int long long
//#define inf 10000000000000001ll
//#define fi first
//#define se second
typedef long long ll;
using namespace std;
bool ok=false;
int a[2][200001];
int n;
bool used[2][200001];
void dfs(int x,int y){
   // cout<<x<<" "<<y<<" "<<a[x][y]<<endl;
     if (x==1 && y==n && (a[x][y]==2 || a[x][y]==3 || a[x][y]==6)){
        ok=true;
        return;
     }
     used[x][y]=true;
     if (a[x][y]==2 || a[x][y]==3 || a[x][y]==6){
        if (y<n && !used[x][y+1]) {
            if (a[x][y+1]<=2) a[x][y+1]=2;
            else if (x==0) a[x][y+1]=4;
            else a[x][y+1]=5;
            dfs(x,y+1);
        }
     } else if (a[x][y]==4){
        if (x==0 && !used[x+1][y]) {
            if (a[x+1][y]<=2) a[x+1][y]=1;
            else a[x+1][y]=6;
            dfs(x+1,y);
        }
     } else if (a[x][y]==5){
        if (x==1 && !used[x-1][y]) {
            if (a[x-1][y]<=2) a[x-1][y]=1;
            else a[x-1][y]=3;
            dfs(x-1,y);
        }
     }
}
void solve(){
    ok=false;
    cin>>n;
    for (int i=1;i<=n;i++) {
        char c;cin>>c;
        a[0][i]=(c-'0');
    }
    for (int i=1;i<=n;i++) {
        char c;cin>>c;
        a[1][i]=(c-'0');
    }
    if (a[0][1]<=2) a[0][1]=2;
    else a[0][1]=4;
    for (int i=0;i<=1;i++) for (int j=0;j<=n;j++) used[i][j]=false;
    dfs(0,1);
    if (ok) cout<<"YES\n";
    else cout<<"NO\n";
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}