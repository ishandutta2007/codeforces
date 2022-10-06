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
template<class T> ostream& operator<<(ostream &os, const deque<T> &t) {
os<<"{"; rep(i,t.size()) {os<<t[i]<<",";} os<<"}"<<endl; return os;}
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

vector<int> solve(vector<int> bs,vector<int> cs){
	auto zip=bs; zip.insert(zip.end(),all(cs));
	sort(all(zip)); UNIQUE(zip);
	out(zip,1);
	int n=zip.size();
	vector<multiset<int>> g(n);
	rep(i,bs.size()){
		int x=lower_bound(all(zip),bs[i])-zip.begin();
		int y=lower_bound(all(zip),cs[i])-zip.begin();
		out(x,y,1);
		g[x].emplace(y);
	  g[y].emplace(x);
	}
	vector<int> re,er{0};
	rep(i,n)if(g[i].size()%2){
		er.back()=i;
	}
	while(er.size()){
		for(int v=er.back(); g[v].size(); v=er.back()){
			er.pb(*g[v].begin());
			g[v].erase(g[v].begin());
			g[er.back()].erase(g[er.back()].find(v));
		}
		re.pb(er.back());
		er.pop_back();
		out(er,re,1);
	}
	//rep(i,n)for(int j:g[i]) out(i,j,1);
	// rep(i,n)if(g[i].size()){
	// 	cout<<"-1\n"; return 0;
	// }
	out(re,1);
	vector<pii> A,B;
	rep(i,bs.size()) A.eb(bs[i],cs[i]);
	for(int &x:re) x=zip[x];
	reps(i,1,re.size()){
		int x=re[i];
		int y=re[i-1];
		if(x>y) swap(x,y);
		B.eb(x,y);
	}
	out(A,B,1);
	sort(all(A)); sort(all(B));
	if(A!=B){
		return {-1};
	}
	return re;
}

int main(){
	// rep(_,100){
	// 	int n=rand()%10000+2;
	// 	vector<int> a;
	// 	rep(i,n) a.pb(rand());
	// 	vector<int> b,c;
	// 	reps(i,1,n){
	// 		b.pb(min(a[i-1],a[i]));
	// 		c.pb(max(a[i-1],a[i]));
	// 	}
	// 	if(solve(b,c)==vector<int>{-1}){
	// 		cout<<a<<endl;
	// 		return 0;
	// 	}
	// }
	// return 0;
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
	int n;
	cin>>n; --n;
	vector<int> bs(n),cs(n);
	rep(i,n) cin>>bs[i];
	rep(i,n) cin>>cs[i];
	auto re=solve(bs,cs);
	for(int x:re) cout<<x<<" "; cout<<endl;
  return 0;
}