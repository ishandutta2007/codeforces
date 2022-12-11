#include<bits/stdc++.h>
#define fors(i,a,b) for(int i = a; i < b; ++i)
#define ll long long
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
#define all(x) x.begin(),x.end()
#define pb push_back
using namespace std;
const int maxn = 2e3+5;
int f[maxn][maxn];
const int mod = 1e9+7;
int k;
int qm(int a, int b){
    int res = 1;
    while(b){
        if(b&1) res = (ll)res*a%mod;
        a = (ll)a*a%mod; b >>= 1;
    }return res;
}
const int inv2 = (mod+1)/2;
int dfs(int n, int m){
    if(n == m) return (ll)n*k%mod;
    if(f[n][m]!=-1) return f[n][m];
    int x = (dfs(n-1,m)-dfs(n-1,m-1))%mod;
    x = (x+mod)%mod;
    x = (ll)x*inv2%mod;
    f[n][m] = (dfs(n-1,m-1)+x)%mod;
    return f[n][m];
}
int main(){
    int T; cin>>T;
    while(T--){
        int n, m; 
        cin>>n>>m>>k;
        fors(i,0,n+1) fors(j,0,m+1) f[i][j] = -1;
        int ans = dfs(n, m);
        cout<<ans<<endl;
    }
    return 0;
}