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
template<class S, class T> ostream& operator<<(ostream &os, const pair<S,T> &t) { return os<<"("<<t.first<<","<<t.second<<")";}
template<class T> inline bool MX(T &l,const T &r){return l<r?l=r,1:0;}
template<class T> inline bool MN(T &l,const T &r){return l>r?l=r,1:0;}
#define out(args...){vector<string> a_r_g_s=s_p_l_i_t(#args, ','); e_r_r(a_r_g_s.begin(), args); }
vector<string> s_p_l_i_t(const string &s, char c){vector<string> v;int d=0,f=0;string t;for(char c:s){if(!d&&c==',')v.pb(t),t="";else t+=c;if(c=='\"'||c=='\'')f^=1;if(!f&&c=='(')++d;if(!f&&c==')')--d;}v.pb(t);return move(v);}
void e_r_r(vector<string>::iterator it) {}
template<typename T, typename... Args> void e_r_r(vector<string>::iterator it, T a, Args... args){ if(*it==" 1"||*it=="1") cerr<<endl; else cerr << it -> substr((*it)[0] == ' ', it -> length()) << " = " << a << ", "; e_r_r(++it, args...);}
const ll MOD=1e9+7;
const ll INF = 1e12;
int n;
void solve(vector<pll> &re,const vector<tuple<int,int,int>> &vs){
	vector<ll> mn(n,INF);
	ll sum=n*INF, mns=INF;
	for(auto tp:vs){
		int d,v,c;
		tie(d,v,c)=tp;
		sum-=mn[v];
		MN<ll>(mn[v],c);
		sum+=mn[v];
		if(MN(mns,sum))
			re.eb(d,sum);
	}
}
int main(){
	int m,t;
	scanf("%d%d%d",&n,&m,&t);
	vector<tuple<int,int,int>> in,out;
	rep(i,m){
		int d,f,t,c;
		scanf("%d%d%d%d",&d,&f,&t,&c);
		if(f==0){
			out.eb(d,t-1,c);
		}else{
			in.eb(d,f-1,c);
		}
	}
	sort(all(in));
	sort(rall(out));
	vector<pll> A,B;
	solve(A,in);
	B.eb(INF,INF);// reverse(all(B));
	solve(B,out);
	//out(A,B,1);
	ll re=INF;
	for(pll p:A){
		while(p.X+t>=B.back().X) B.pop_back();
		MN(re, p.Y+B.back().Y);
	}
	printf("%lld\n",(re==INF?-1:re));
  return 0;
}