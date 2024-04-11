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
const int mod=998244353;
const int INF=LLONG_MAX/4;
const double EPS=1e-9;
const int N=300007;
int _;
signed main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin>>_;
    while (_--){
        int n;
        cin>>n;
        vi a(n,0);
        rep(i,n) cin>>a[i];
        vi cnt(n+1,0);
        rep(i,n) cnt[a[i]]++;
        set<int> s;
        rep(i,n){
            s.insert(a[i]);   
        } 
        int ans=0;
        while (s.find(ans)!=s.end()) ans++;
        if (0){}
        else{
            s.clear();
            int cur=0;
            vi ans;
            rep(i,n){
                s.insert(a[i]);
                cnt[a[i]]--;
                while (s.find(cur)!=s.end()) cur++;
                if (!cnt[cur]){
                    ans.pb(cur);
                    cur=0, s.clear();
                }
            }
            cout<<sz(ans)<<"\n";
            for (auto c:ans) cout<<c<<" ";
            cout<<"\n";
        }
    }
    return 0;
}