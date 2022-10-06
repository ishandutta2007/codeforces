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
#ifdef __cpp_init_captures
template<typename T>vector<T> table(int n, T v){ return vector<T>(n, v);}
template <class... Args> auto table(int n, Args... args){auto val = table(args...); return vector<decltype(val)>(n, move(val));}
#endif
const ll MOD=1e9+7;

int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
	int n,t;
	cin>>n>>t;
	vector<int> a(n);
	rep(i,n) cin>>a[i];
	vector<int> b;
	for(int x:a){
		if(x==1){
			if(b.size() && b.back()<0) --b.back();
			else b.eb(-1);
		}else{
			b.pb(x);
		}
	}
	int m=b.size();
	ll re=0;
	rep(i,m){
		ll p=1,s=0;
		reps(j,i,m){
			int x=b[j];
			if(x<0){
				ll d=p-s*t;
				if(d>0 && d%t==0 && d/t<=-x){
					++re;
					out(i,j,d/t,1);
				}
				s+=-x;
			}else{
				if(p>ll(3e18)/x) break;
				p*=x;
				s+=x;
				if(p==s*t) ++re;
				if(p==s*t) out(i,j,1);
			}
		}
		if(b[i]<-1){
			reps(ii,1,-b[i]){
				ll p=1,s=ii;
				if(t==1) ++re;
				reps(j,i+1,m){
					int x=b[j];
					if(x<0){
						ll d=p-s*t;
						if(d>0 && d%t==0 && d/t<=-x){
							++re;
							out(i,j,d/t,1);
						}
						s+=-x;
					}else{
						if(p>ll(3e18)/x) break;
						p*=x;
						s+=x;
						if(p==s*t) ++re;
				if(p==s*t) out(i,j,1);
					}
				}
			}
		}
	}
	out(a,b,re,1);
	cout<<re<<endl;
  return 0;
}