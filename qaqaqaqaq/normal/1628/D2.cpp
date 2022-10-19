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
    f[0]=1;
    int inv2=(mod+1)/2;
    for (int i=1;i<=1000000;++i) f[i]=f[i-1]*i%mod;
    rf[1000000]=modpow(f[1000000],mod-2);
    for (int i=1000000;i>0;--i) rf[i-1]=rf[i]*i%mod;
    while (_--){
        cin>>n>>m>>k;
        auto C=[&](int u,int v){
            if (u<0||v<0||u<v) return 0ll;
            return f[u]*rf[v]%mod*rf[u-v]%mod;  
        };
        m=n-m;
        if (m==0){
            cout<<n*k%mod<<"\n";
            continue;
        }
        int ans=0;
        int prob=0;
        for (int w=0;w<n;++w){
            ans=(ans+C(w,m-1)*modpow(inv2,w)%mod*(n-w-1))%mod;
        }
        cout<<ans*k%mod*inv2%mod<<"\n";
    }
    return 0;
}