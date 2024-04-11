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
#undef NUIP
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

using TP=tuple<int,int,int,int>;

void solve_(vv<string> &mp,vector<TP> &re,int f=0){
	int n=mp.size();
	int m=mp[0].size();
	rep(x,2){
		rep(_,mp[0][x].size()) re.eb(x,0,x,1);
		if(f)	mp[1][x]=mp[1][x]+mp[0][x];
		else mp[1][x]=mp[0][x]+mp[1][x];
		mp[0][x]="";
	}
	rep(y,n)rep(x,m){
		rrep(i,mp[y][x].size()) re.eb(x,y,mp[y][x][i]-'0',0);
	}
}
void solve(vv<string> &mp,vector<TP> &re,vector<pii> &ps){
	int n=mp.size();
	int m=mp[0].size();
	ps.resize(n);
	rep(y,n)rep(x,m){
		rrep(i,mp[y][x].size()){
			int X=mp[y][x][i]-'0';
			int Y=y;
			if(x==X && y==Y) Y=!Y;
			re.eb(x,y,X,Y);
			if(X) ++ps[Y].Y;
			else ++ps[Y].X;
		}
	}
}

int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
	int n,m;
	cin>>n>>m;
	vv<string> A(n,vector<string>(m));
	vv<string> B(n,vector<string>(m));
	rep(i,n)rep(j,m) cin>>A[i][j];
	rep(i,n)rep(j,m) cin>>B[i][j];
	vector<TP> a,b;
	vector<pii> p,q;
	solve(A,a,p);
	rep(i,n)rep(j,m) reverse(all(B[i][j]));
	solve(B,b,q);
	reverse(all(b));
	vector<int> xs,xt,ys,yt;
	rep(i,n){
		reps(_,p[i].X,q[i].X) xt.pb(i);
		reps(_,q[i].X,p[i].X) xs.pb(i);
		reps(_,p[i].Y,q[i].Y) yt.pb(i);
		reps(_,q[i].Y,p[i].Y) ys.pb(i);
	}
	vector<TP> re;
	for(auto tp:a){
		int x,y,X,Y;
		tie(x,y,X,Y)=tp;
		re.eb(x,y,X,Y);
	}
	rep(i,xs.size()){
		re.eb(0,xs[i],0,xt[i]);
	}
	rep(i,ys.size()){
		re.eb(1,ys[i],1,yt[i]);
	}
	out(1);
	for(auto tp:b){
		int x,y,X,Y;
		tie(X,Y,x,y)=tp;
		re.eb(x,y,X,Y);
	}
#ifndef NUIP
	cout<<re.size()<<endl;
	for(auto tp:re){
		int x,y,X,Y;
		tie(x,y,X,Y)=tp;
		cout<<y+1<<" "<<x+1<<" "<<Y+1<<" "<<X+1<<"\n";
	}
#endif
#ifdef NUIP
	auto yabai=[&](){ out(A,B,re,1); exit(0); };
	out(a.size(),xs.size(),ys.size(),b.size(),re.size(),1);
	for(auto tp:re){
		int x,y,X,Y;
		tie(x,y,X,Y)=tp;
		if(A[y][x].empty()) yabai();
		A[Y][X]=A[y][x].back()+A[Y][X];
		A[y][x].pop_back();
		out(x,y,X,Y,1);
		rep(i,n){rep(j,m) cout<<A[i][j]<<",";cout<<endl;}
	}
	rep(i,n)rep(j,m) reverse(all(A[i][j]));
	out("rev",1);
	if(A!=B) yabai();
#endif
  return 0;
}