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
template<typename T>vector<T> table(int n, T v){ return vector<T>(n, v);}
template <class... Args> auto table(int n, Args... args){auto val = table(args...); return vector<decltype(val)>(n, move(val));}
const ll MOD=1e9+7;

int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
	vector<string> re(256);
	vector<string> d[3];
	rep(i,3) d[i].resize(256);
	d[2][0b01010101]="z";
	d[2][0b00110011]="y";
	d[2][0b00001111]="x";
	int msk=0b11111111;
	auto upd=[&](int j,vector<string> &d,const string &s)->bool{
		if(d[j].size()==s.size()){ return MN(d[j],s);}
		if(d[j].empty() || d[j].size()>s.size()){ d[j]=s; return 1;}
		return 0;
	};
	while(1){
		rep(i,256)if(d[2][i].size()){
			upd(msk&~i,d[2],"!"+d[2][i]);
		}

		while(1){
			int f=0;
			reps(ii,1,3)rep(i,256)if(d[ii][i].size())
				reps(jj,1,3)rep(j,256)if(d[jj][j].size()) f|=upd(i&j,d[1],d[ii][i]+"&"+d[jj][j]);
			if(!f) break;
		}

		while(1){
			int f=0;
			reps(ii,0,3)rep(i,256)if(d[ii][i].size())
				reps(jj,0,3)rep(j,256)if(d[jj][j].size()) f|=upd(i|j,d[0],d[ii][i]+"|"+d[jj][j]);
			if(!f) break;
		}

		int f=0;
		rep(ii,3)rep(i,256)if(upd(i,re,d[ii][i])) f=1;
		rep(ii,2)rep(i,256)if(d[ii][i].size()) f|=upd(i,d[2],"("+d[ii][i]+")");
		if(!f) break;
	}
	int n;
	cin>>n;
	vector<int> a(n);
	rep(i,n){
		string s;
		cin>>s;
		int &v=a[i];
		for(char c:s) (v*=2)+=c-'0';
	}
	rep(i,n) cout<<re[a[i]]<<"\n";
  return 0;
}