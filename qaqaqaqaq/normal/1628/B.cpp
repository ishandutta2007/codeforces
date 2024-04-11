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
const int N=30*30*30;
int _;

signed main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin>>_;
    while (_--){
        int n;
        cin>>n;
        vector<string> s(n);
        rep(i,n) cin>>s[i];
        set<string> st;
        for (int i=0;i<n;++i){
            if (sz(s[i])==1){
                cout<<"YES\n";
                goto cont;
            }
            if (sz(s[i])==2){
                if (s[i][0]==s[i][1]){
                    cout<<"YES\n";
                    goto cont;
                }
                if (st.find(s[i])!=st.end()){
                    cout<<"YES\n";
                    goto cont;
                }
                rep(j,26){
                    reverse(range(s[i]));
                    s[i].pb(j+'a');
                    reverse(range(s[i]));
                    if (st.find(s[i])!=st.end()){
                        cout<<"YES\n";
                        goto cont;
                    }
                    reverse(range(s[i]));
                    s[i].pop_back();
                    reverse(range(s[i]));
                }
                reverse(range(s[i]));
                st.insert(s[i]);
            }
            else{
                if (s[i][0]==s[i][2]){
                    cout<<"YES\n";
                    goto cont;
                }
                if (st.find(s[i])!=st.end()){
                    cout<<"YES\n";
                    goto cont;
                }
                if (st.find(s[i].substr(1,2))!=st.end()){
                    cout<<"YES\n";
                    goto cont;
                }
                reverse(range(s[i]));
                st.insert(s[i]);
            }
        }
        cout<<"NO\n";
        cont:; 
    }
    return 0;
}