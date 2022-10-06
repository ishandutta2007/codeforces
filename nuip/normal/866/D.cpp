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
template<typename T>vector<T> table(int n, T v){ return vector<T>(n, v);}
template <class... Args> auto table(int n, Args... args){auto val = table(args...); return vector<decltype(val)>(n, move(val));}
const ll MOD=1e9+7;
const int MAX_N=(1<<19);
int nn=MAX_N;

struct Seg{
 int mx,ind;
  Seg(int d=-2000000,int i=100000){
    mx=d;
    ind=i;
  }
  static Seg e;
};
vector<Seg> dat(2*MAX_N);
Seg Seg::e=Seg();

Seg operator+(Seg l,Seg r){
  return l.mx>=r.mx?l:r;
}
//ostream& operator<<(ostream &os, const Seg &t) { return os<<"["<<t.mn<<")";}
template<class T=Seg> void upd(int k,T a,vector<T> &dat=dat){
  k+=dat.size()/2-1;
  dat[k]=a;
  while(k>0){
    k=(k-1)/2;
    dat[k]=dat[k*2+1]+dat[k*2+2];
  }
}

//(l,r,0,0,nn)
template<class T=Seg> T query(int a,int b,const vector<T> &dat=dat,int k=0,int l=0,int r=-1){
  if(r<0) r=dat.size()/2;
  if(r<=a || b<=l)return T::e;
  if(a<=l && r<=b) return dat[k];
  T lv=query(a,b,dat,k*2+1,l,(l+r)/2) ,rv= query(a,b,dat,k*2+2,(l+r)/2,r);
  return lv+rv;
}

vector<int> inds[1123456];

int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
	int n;
	cin>>n;
	vector<int> ps(n);
	rep(i,n) cin>>ps[i];
	rep(i,n)inds[ps[i]].pb(i);
	set<int> gt;
	rep(i,n) gt.insert(i);
	vector<int> shot(n);
	ll re=0;
	rep(i,1000006){
		for(int x:inds[i]){
			auto it=gt.find(x);
			if(it!=gt.end()) gt.erase(it);
		}
		for(int x:inds[i]){
			auto it=gt.lower_bound(x);
			if(it==gt.end()) continue;
			int y=*it;
			shot[y]=1;
			gt.erase(it);
			re+=ps[y]-ps[x];
			if(shot[x]){
				auto it=gt.lower_bound(x);
				if(it==gt.end()) continue;
				int y=*it;
				shot[y]=1;
				gt.erase(it);
				re+=ps[y]-ps[x];
			}				
		}
	}
	cout<<re<<endl;
  return 0;
}