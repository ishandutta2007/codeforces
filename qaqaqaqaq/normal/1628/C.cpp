// #pragma comment(linker, "/STACK:102400000,102400000")
#pragma GCC optimize("O3")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
// #pragma GCC optimize("trapv")
#include<bits/stdc++.h>
 
#define int long long
using namespace std;
 
namespace std {
 
template<class Fun>
class y_combinator_result {
	Fun fun_;
public:
	template<class T>
	explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
 
	template<class ...Args>
	decltype(auto) operator()(Args &&...args) {
		return fun_(std::ref(*this), std::forward<Args>(args)...);
	}
};
 
template<class Fun>
decltype(auto) y_combinator(Fun &&fun) {
	return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}
 
} // namespace std
 
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
 
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
const int mod=1e9+7;
const int INF=LLONG_MAX/4;
const double EPS=1e-9;
const int N=30*30*30;
int _;
int n,m,k;
int f[1000007],rf[1000007];
int modpow(int u,int v){
    int ans=1,t=u;
    while (v){
        if (v&1) ans=ans*t%mod;
        t=t*t%mod, v>>=1;
    }
    return ans;
}
signed main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin>>_;
    while(_--){
        int n;
        cin>>n;
        vector<vi> a(n,vi(n,0)),b(n,vi(n,0));
        rep(i,n) rep(j,n) cin>>a[i][j];
        rep1(i,n-1) rep(j,n){
            b[i][j]=a[i-1][j]^(i-1>0?b[i-2][j]:0)^(j>0?b[i-1][j-1]:0)^(j+1<n?b[i-1][j+1]:0);
        }
        int ans=0;
        rep(i,n) rep(j,n) ans^=b[i][j];
        cout<<ans<<"\n";
    }
    return 0;
}