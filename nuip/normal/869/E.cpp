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
#include<random>
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
template<typename T>vector<T> table(int n, T v){ return vector<T>(n, v);}
template <class... Args> auto table(int n, Args... args){auto val = table(args...); return vector<decltype(val)>(n, move(val));}
const ll MOD=1e9+7;

const int nn=2525;
ll bit[nn+1][nn+1];

int sum(int y,int x){ ++y; ++x;
  int s=0;
  while(y>0){
		int i=x;
		while(i>0){
			s^=bit[y][i];
			i-=i&-i;
		}
		y-=y&-y;
	}
  return s;
}

void add(ll y,ll x,int v){ ++y; ++x;
  while(y<=nn){
		int i=x;
		while(i<=nn){
			bit[y][i]^=v;
			i+=i&-i;
		}
		y+=y&-y;
	}
}

int memo[2525][2525];

int main(){
	int n,m,q;
	scanf("%d%d%d",&n,&m,&q);
	mt19937 rndm(time(0));
	while(q--){
		int t,x,y,X,Y;
		scanf("%d%d%d%d%d",&t,&y,&x,&Y,&X);
		if(t==1){
			++Y; ++X;
			int ad=rndm();
			memo[y][x]=ad;
			add(y,x,ad);
			add(Y,x,ad);
			add(y,X,ad);
			add(Y,X,ad);
		}else if(t==2){
			++Y; ++X;
			int ad=memo[y][x];
			add(y,x,ad);
			add(Y,x,ad);
			add(y,X,ad);
			add(Y,X,ad);
		}else if(t==3){
			printf(sum(y,x)==sum(Y,X)?"Yes\n":"No\n");
		}
	}
  return 0;
}