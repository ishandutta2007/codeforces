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

int solve(vector<int> a){
	int n=a.size();	
	vv<int> inv(n+1);
	set<int> neg;
	rep(i,n){
		if(a[i]>=0){
			inv[a[i]].pb(i);
		}
	}
	rep(i,n)if(a[i]<0){
		 neg.emplace(i);
	}
	queue<int> que; que.emplace(n);
	vector<int> usd(n+1);
	vector<int> re(n+1);
	int cur=n;
	while(1){
		while(que.size()){
			int v=que.front(); que.pop();
			re[v]=cur--;
			// for(int w:inv[v])if(a[w]<0) neg.emplace(w);
			if(usd[v]){ cout<<-1<<"\n"; return 0;}
			usd[v]=1;
			out(v,cur,1);
			if(v==0 || usd[v-1]) continue;
			if(inv[v].empty()){
				auto it=neg.lower_bound(v);
				if(it==neg.begin()){ cout<<-1<<"\n"; return 0;}
				--it;
				int w=*it;
				inv[v].pb(w);
				neg.erase(w);
			}
			for(auto w:inv[v]) que.emplace(w);
			// for(auto x:neg) out(x); out(1);
		}
		if(neg.empty()) break;
		int w=*neg.rbegin();
		que.emplace(w);
		neg.erase(w);
	}
	if(cur!=-1){ cout<<-1<<"\n"; return 0;}
	deque<pii> dq; dq.emplace_front(n,n);
	vector<int> used(n);
	rrep(i,n){
		int x=lower_bound(all(dq),pii(re[i],0))->Y;
		used[re[i]]=1;
		if(a[i]>=0 && x != a[i]){ cout<<-1<<"\n"; return 0;}
		while(re[i]>dq.front().X) dq.pop_front();
		dq.emplace_front(re[i],i);
	}
	rep(i,n)if(!used[i]){ cout<<-1<<"\n"; return 0;}
	rep(i,n) cout<<re[i]+1<<" \n"[i+1==n];
	return 1;
}

int main(){
	// solve({4,-1,-1,-1,});
	// rep(_,10000){
	// 	int n=rand()%50+1;
	// 	vector<int> perm(n); iota(all(perm),0); random_shuffle(all(perm));
	// 	vector<int> a(n);
	// 	const int N=n+10;
	// 	deque<pii> dq; dq.emplace_front(n,n);
	// 	vector<int> used(n);
	// 	rrep(i,n){
	// 		int x=lower_bound(all(dq),pii(perm[i],0))->Y;
	// 		a[i]=x;
	// 		while(perm[i]>dq.front().X) dq.pop_front();
	// 		dq.emplace_front(perm[i],i);
	// 	}
	// 	auto orig=a;
	// 	int m=rand()%n+1;
	// 	vector<int> neg(m,1); neg.resize(n); random_shuffle(all(neg));
	// 	rep(i,n)if(neg[i]) a[i]=-1;
	// 	if(solve(a)==0){
	// 		out(perm,a,orig,1);
	// 		return 0;
	// 	}
	// }
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		vector<int> a(n);
		rep(i,n){
			cin>>a[i];
			if(a[i]>=0) --a[i];
		}
		solve(a);
	}
  return 0;
}