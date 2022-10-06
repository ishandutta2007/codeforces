#include <string>
#include <vector>
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<stack>
#include<queue>
#include<cmath>
#include<algorithm>
#include<functional>
#include<list>
#include<deque>
#include<bitset>
#include<set>
#include<map>
#include<unordered_map>
#include<unordered_set>
#include<cstring>
#include<sstream>
#include<complex>
#include<iomanip>
#include<numeric>
#include<cassert>
#define X first
#define Y second
#define pb push_back
#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define reps(X,S,Y) for (int (X) = S;(X) < (Y);++(X))
#define rrep(X,Y) for (int (X) = (Y)-1;(X) >=0;--(X))
#define rreps(X,S,Y) for (int (X) = (Y)-1;(X) >= (S);--(X))
#define repe(X,Y) for ((X) = 0;(X) < (Y);++(X))
#define peat(X,Y) for (;(X) < (Y);++(X))
#define all(X) (X).begin(),(X).end()
#define rall(X) (X).rbegin(),(X).rend()
#define eb emplace_back
#define UNIQUE(X) (X).erase(unique(all(X)),(X).end())
#define Endl endl

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<class T> using vv=vector<vector<T>>;
template<class T> ostream& operator<<(ostream &os, const vector<T> &t) {
os<<"{"; rep(i,t.size()) {os<<t[i]<<",";} os<<"}"<<endl; return os;}
template<class T,size_t n> ostream& operator<<(ostream &os, const array<T,n> &t) {
	os<<"{"; rep(i,n) {os<<t[i]<<",";} os<<"}"<<endl; return os;}
template<class S, class T> ostream& operator<<(ostream &os, const pair<S,T> &t) { return os<<"("<<t.first<<","<<t.second<<")";}
template<class S, class T,class U> ostream& operator<<(ostream &os, const tuple<S,T,U> &t) { return os<<"("<<get<0>(t)<<","<<get<1>(t)<<","<<get<2>(t)<<")";}
template<class S, class T,class U,class V> ostream& operator<<(ostream &os, const tuple<S,T,U,V> &t) { return os<<"("<<get<0>(t)<<","<<get<1>(t)<<","<<get<2>(t)<<","<<get<3>(t)<<")";}
template<class S, class T,class U,class V,class W> ostream& operator<<(ostream &os, const tuple<S,T,U,V,W> &t) { return os<<"("<<get<0>(t)<<","<<get<1>(t)<<","<<get<2>(t)<<","<<get<3>(t)<<","<<get<4>(t)<<")";}
template<class T> inline bool MX(T &l,const T &r){return l<r?l=r,1:0;}
template<class T> inline bool MN(T &l,const T &r){return l>r?l=r,1:0;}
//#undef NUIP
#ifdef NUIP
#define out(args...){vector<string> a_r_g_s=s_p_l_i_t(#args, ','); e_r_r(a_r_g_s.begin(), args); }
vector<string> s_p_l_i_t(const string &s, char c){vector<string> v;int d=0,f=0;string t;for(char c:s){if(!d&&c==',')v.pb(t),t="";else t+=c;if(c=='\"'||c=='\'')f^=1;if(!f&&c=='(')++d;if(!f&&c==')')--d;}v.pb(t);return move(v);}
void e_r_r(vector<string>::iterator it) {}
template<typename T, typename... Args> void e_r_r(vector<string>::iterator it, T a, Args... args){ if(*it==" 1"||*it=="1") cerr<<endl; else cerr << it -> substr((*it)[0] == ' ', it -> length()) << " = " << a << ", "; e_r_r(++it, args...);}
#else
#define out
#endif
#ifdef __cpp_init_captures
template<typename T>vector<T> table(int n, T v){ return vector<T>(n, v);}
template <class... Args> auto table(int n, Args... args){auto val = table(args...); return vector<decltype(val)>(n, move(val));}
#endif
const ll MOD=1e9+7;

int dp[1123456];
vector<int> vs[1123456];
int dst[333][6334];
int re[333][333];

namespace std{
	template<>
	class hash<vector<int>>{
	public:
		size_t operator () ( const vector<int> &p ) const{
			int h=0;
			for(int x:p) (h*=4)+=x;
			return h;
		}
	};
}

int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0); cin.tie(0);
  fill(dp,dp+1123456,1);
	reps(p,2,1023456)if(dp[p]==1){
		for(int i=p;i<1023456;i+=p){
			int cnt=0;
			for(int j=i;j%p==0;j/=p) ++cnt;
			dp[i]*=cnt+1;
			vs[i].pb(cnt);
		}
	}
	unordered_set<vector<int>> st{{}};
	reps(p,2,1000001){
		sort(rall(vs[p]));
		st.emplace(vs[p]);
	}
	out(st.size(),1);
	unordered_map<vector<int>,int> ind;
	{
		queue<vector<int>> que;
		unordered_map<vector<int>,int> dst;
		for(auto v:st){
			dst[v]=0;
			que.emplace(v);
			int tmp=ind.size();
			ind[v]=tmp;
		}
		const int UB=18;//18+6;
		while(que.size()){
			auto v=que.front(); que.pop();
			int n=v.size();
			if(dst[v]==UB) continue;
			rep(i,n+1){
				auto w=v;
				if(i<n){
					if(i && v[i]==v[i-1]) continue;
					++w[i];
				}else{
					w.pb(1);
				}
				if(dst.count(w)==0){
					int tmp=ind.size();
					ind[w]=tmp;
					dst[w]=dst[v]+1;
					que.emplace(w);
				}
			}
		}
		out(dst.size(),1);
	}
	
	const int N=ind.size();
	vv<int> g(N);
	vector<int> prd(N,1);
	for(auto p:ind){
		auto v=p.X;
		for(int x:v) prd[p.Y]*=x+1;
		vector<int> ne;
		rep(i,v.size()+1){
			auto w=v;
			if(i<v.size()){
				if(i && v[i]==v[i-1]) continue;
				++w[i];
			}else{
				w.pb(1);
			}
			if(ind.count(w)) ne.pb(ind[w]);
		}
		// rep(i,v.size()){
		// 	auto w=v;
		// 	--w[i];
		// 	if(!w[i]) w.erase(w.begin()+i);
		// 	sort(all(w));
		// 	if(ind.count(w)) ne.pb(ind[w]);
		// }
		sort(all(ne)); UNIQUE(ne);
		for(int x:ne){
			g[p.Y].pb(x);
			g[x].pb(p.Y);
		}
	}
	{
		auto tmp=prd;
		sort(all(tmp)); UNIQUE(tmp);
		for(int &x:prd) x=lower_bound(all(tmp),x)-tmp.begin();
		out(tmp.size(),1);
	}//return 0;

	const int oN=st.size();
	fill(dst[0],dst[oN],MOD);
	rep(rt,oN){
		vector<int> dst(N,MOD); dst[rt]=0;
		queue<int> que; que.emplace(rt);
		while(que.size()){
			int v=que.front(); que.pop();
			for(int w:g[v])if(MN(dst[w],dst[v]+1)) que.emplace(w);
		}
		if(!rt) out(dst[173],1);
		rep(i,N) MN(::dst[rt][prd[i]],dst[i]);
	}
	rep(a,oN)rep(b,oN){
		int ret=MOD;
		rep(i,555) MN(ret,dst[a][i]+dst[b][i]);
		re[a][b]=re[b][a]=ret;
	}
	int T;
	cin>>T;
	while(T--){
		int a,b;
		cin>>a>>b;
		int x=ind[vs[a]];
		int y=ind[vs[b]];
		out(vs[a],x,vs[b],y,1);
		cout<<re[x][y]<<"\n";
	}
	return 0;
}