// #pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
#define int long long
using namespace std;
 
#define rep(i,n) for (int i=0;i<(int)(n);++i)
#define rep1(i,n) for (int i=1;i<=(int)(n);++i)
#define range(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define F first
#define S second
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int inf=LLONG_MAX/4;
mt19937 rng(time(NULL)); // don't hack, pls!

const int maxn=100007;
const int mod=998244353;
const double EPS=1e-9;
const double pi=3.14159265358979;

int n,m;
int a[maxn],p[maxn];
int b[307][307];
void solve(){
    memset(b,0,sizeof(b));
    cin>>n>>m;
    rep(i,n) rep(j,m) cin>>a[i*m+j];
    a[n*m]=inf;
    rep(i,n*m+1) p[i]=i;
    sort(p,p+n*m,[&](int u,int v){return a[u]>a[v]||(a[u]==a[v]&&u<v);});
    // int ans=0;
    int prv=a[p[0]],l=0;
    rep(i,n*m+1){
        if (prv==a[p[i]]) continue;
        int min_row=l/m, max_row=(i-1)/m;
        if (min_row==max_row){
            for (int j=l;j<i;++j) b[j/m][j%m]=p[j];
        }
        else{
            int le=l, ri=i;
            for (int j=(l/m+1)*m-1;j>=l;--j){
                ri--, b[j/m][j%m]=p[ri];
            }
            for (int j=max_row*m;j<i;++j){
                b[max_row][j%m]=p[le++];
            }
        }
        prv=a[p[i]], l=i;
    }
    // rep(i,n){
    //     rep(j,m){
    //         cout<<b[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    int ans=0;
    rep(i,n){
        rep(j,m){
            rep(k,j){
                ans+=(b[i][j]<b[i][k]);
            }
        }
    }
    cout<<ans<<"\n";
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.precision(20);
    int _;
    cin>>_;
    while (_--){
        solve();
    }
    return 0;
}

/*
2
101919804931827191 136638622643121931

*/