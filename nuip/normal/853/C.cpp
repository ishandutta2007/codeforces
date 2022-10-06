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

const int nn=212345;
ll bit[nn+1];

ll sum(int i){ ++i;
  ll s=0;
  while(i>0){
    s+=bit[i];
    i-=i&-i;
  }
  return s;
}

void add(int i,ll x){ ++i; ++i;
  while(i<=nn){
    bit[i]+=x;
    i+=i&-i;
  }
}

int main(){
	int n,q;
	scanf("%d%d",&n,&q);
	vector<pii> ps(n);
	rep(i,n) scanf("%d",&ps[i].Y), --ps[i].Y, ps[i].X=i;
	vector<int> xs(q),ys(q),Xs(q),Ys(q);
	rep(i,q) scanf("%d%d%d%d",&xs[i],&ys[i],&Xs[i],&Ys[i]), --xs[i], --ys[i], --Xs[i], --Ys[i];
	xs.pb(MOD);
	vector<ll> re(q,n*(n-1ll)/2);
	rep(_,4){
		fill(bit,bit+nn,0);
		sort(all(ps));
		vector<int> ind(q+1); iota(all(ind),0);
		sort(rall(ind),[&](int i,int j){return xs[i]<xs[j];});
		//solve
		rep(i,n){
			for(;xs[ind.back()]==i; ind.pop_back()){
				ll t=sum(ys[ind.back()]);
				re[ind.back()]-=i*(i-1ll)/2-t*(t-1ll)/2;
			}
			add(ps[i].Y,1);
		}
		for(pii &p:ps) p=pii(p.Y,n-1-p.X);
		rep(i,q){
			int x=xs[i],y=ys[i],X=Xs[i],Y=Ys[i];
			ys[i]=n-1-x; xs[i]=y;
			Ys[i]=n-1-X; Xs[i]=Y;
			if(ys[i]>Ys[i]) swap(ys[i],Ys[i]);
			if(xs[i]>Xs[i]) swap(xs[i],Xs[i]);
		}
	}
	for(ll x:re) printf("%lld\n",x);
  return 0;
}