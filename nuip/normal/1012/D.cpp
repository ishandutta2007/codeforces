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

int solve0(const string &s,const string &t,vector<pii> &re,int inv=0){
	vector<int> a,b;
	auto fun=[&](const string &s,vector<int> &re,int t){
						 int n=s.size();
						 for(int i=0; i<n; t=1-t){
							 re.pb(0);
							 while(i<n && s[i]%2==t) ++re.back(), ++i;
						 }
					 };
	fun(s,a,inv); fun(t,b,1-inv);
	//out(s,a,t,b,1);
	int N=a.size();
	int M=b.size();
	int mn=max(N,M)-1;
	int cut=0;
	rep(i,M){
		int n=0,m=1;
		if((i+1)%2){
			n+=i+1;
		}else if(b[0]==0){
			n+=i;
		}else{
			n+=1+i+1;
		}
		m+=M-(i+1+1);
		//if(!n) n=1;
		n+=N-(i+1)%2-1;
		if(MN(mn,max(n,m))){
			cut=i+1;
		}
	}
	//out(mn,cut,1);
	assert(cut<M);
	if(cut){
		int sum=0;
		rep(i,cut) sum+=b[i];
		re.eb(cut%2?a[0]:0,sum);
		vector<int> A,B{(cut%2?a[0]:0)};
		if(cut%2){
			rep(i,cut) A.pb(b[i]);
		}else if(b[0]==0){
			reps(i,1,cut) A.pb(b[i]);
		}else{
			A.pb(0);
			rep(i,cut) A.pb(b[i]);
		}
		B.back()+=b[cut];
		reps(i,cut+1,M) B.pb(b[i]);
		if(A.size()==0) A.pb(0);
		if(a.size()>cut%2) A.back()+=a[cut%2];
		reps(i,cut%2+1,N) A.pb(a[i]);
		//out(a,b,A,B,1);
		a=A; b=B;
	}
	if(a.size()>b.size()) b.resize(a.size());
	if(b.size()>a.size()) a.resize(b.size());
	int n=a.size();
	int x=0,y=0;
	rep(i,n-1){
		x+=a[i]; y+=b[i];
		re.eb(x,y);
		swap(x,y);
	}
	// {
	// 	out(s,t,1);
	// 	auto S=s,T=t;
	// 	for(pii p:re){
	// 		auto s=T.substr(0,p.Y)+S.substr(p.X);
	// 		auto t=S.substr(0,p.X)+T.substr(p.Y);
	// 		S=s; T=t;
	// 		//out(S,T,p,1);
	// 	}
	// 	rep(i,S.size()) assert(S[0]==S[i]);
	// 	rep(i,T.size()) assert(T[0]==T[i]);
	// }
	return re.size();
}
int solve(string s,string t,vector<pii> &re){
	solve0(s,t,re);
	vector<pii> re2;
	solve0(s,t,re2,1);
	if(re.size()>re2.size()) re=re2;
	return re.size();
}
int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
	// rep(_,10000){
	// 	int n=3+rand()%2,m=20+rand()%2;
	// 	string s,t;
	// 	rep(i,n) s+=char('a'+rand()%2);
	// 	rep(i,m) t+=char('a'+rand()%2);
	// 	vector<pii> hoge;
	// 	solve0(s,t,hoge);
	// }
	string s,t;
	cin>>s>>t;
	vector<pii> re0,re1;
	solve(s,t,re0);
	solve(t,s,re1);
	for(pii &p:re1) swap(p.X,p.Y);
	if(re0.size()>re1.size()) re0=re1;
	cout<<re0.size()<<endl;
	for(pii p:re0) cout<<p.X<<" "<<p.Y<<"\n";
  return 0;
}