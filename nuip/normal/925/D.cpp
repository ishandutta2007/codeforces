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

void no(){ printf("-1\n"); exit(0);}
void yes(vector<int> re){
	int n=re.size();
	printf("%d\n",n-1);
	for(int x:re) printf("%d ",x+1);
	exit(0);
}

struct UF{
  vector<int> data;
  UF(int size):data(size,-1){}
  bool unite(int x,int y){
    x=root(x); y=root(y);
    if(x!=y){
      if(data[y]<data[x]) swap(x,y);
      data[x]+=data[y]; data[y]=x;
    }
    return x!=y;
  }
  bool findSet(int x,int y){return root(x)==root(y);}
  int root(int x){return data[x]<0?x:data[x]=root(data[x]);}
  int size(int x) {return -data[root(x)];}
};

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	vector<pii> es;
	vv<int> g(n);
	rep(i,m){
		int x,y;
		scanf("%d%d",&x,&y); --x; --y;
		es.eb(x,y);
		g[x].pb(y);
		g[y].pb(x);
	}
	out(n,m,es,1);
	UF uf(n);
	for(pii p:es) uf.unite(p.X,p.Y);
	if(uf.findSet(0,n-1)){
		vector<int> dst(n,MOD);dst[0]=0;
		vector<int> prv(n);
		queue<int> que; que.emplace(0);
		while(que.size()){
			int v=que.front(); que.pop();
			for(int w:g[v])if(MN(dst[w],dst[v]+1)){
					que.emplace(w);
					prv[w]=v;
				}
		}
		vector<int> re{n-1};
		while(re.back()){
			int t=prv[re.back()];
			re.pb(t);
		}
		reverse(all(re));
		out(2,re,1);
		if(re.size()>4){
			re.resize(3);
			re.pb(0); re.pb(n-1);
		}
		out(2,re,1);
		yes(re);
	}
	{
		int cnt=0;
		//for(pii e:es)if(uf.findSet(0,e.X)) out(e,1);
		for(pii e:es)if(uf.findSet(0,e.X)) ++cnt;
		ll t=uf.size(0);
		t*=t-1; t/=2;
		out(cnt,t,uf.size(0),1);
		if(t==cnt) no();
	}
	int N=uf.size(0);
	if(N==2) no();
	out(N,1);
	{	
		if(g[0].size()==N-1){
			set<pii> st(all(es));
			UF uf(n);
			reps(i,1,n)for(int j:g[i])if(j) uf.unite(i,j);
			vector<int> cnt(n);
			reps(i,1,n)for(int j:g[i])if(j>i) ++cnt[uf.root(j)];
			for(int v:g[0])if(uf.root(v)==v){
					ll t=uf.size(v);
					t*=t-1; t/=2;
					if(t>cnt[v]){
						int mn=MOD,w;
						for(int i:g[0])if(uf.findSet(v,i) && MN(mn,(int)g[i].size())) w=i;
						for(int v:g[w])if(v)for(int x:g[v])if(x && x!=w && st.count(pii(x,w))==0 && st.count(pii(w,x))==0) yes({0,w,v,x,w,n-1});
						assert(0);
					}
				}
			no();
		}
		vector<int> re{0};
		int rt=0;
		out(rt,1);
		vector<int> A(n),B(n);
		rep(i,n)if(uf.findSet(0,i) && i!=rt && i!=0) B[i]=1;
		for(int w:g[rt])if(w!=0) A[w]=1, B[w]=0;
		for(pii e:es){
			if(A[e.X] && B[e.Y]){
				re.pb(e.X); re.pb(e.Y); re.pb(rt); re.pb(n-1);
				yes(re);
			}
			if(A[e.Y] && B[e.X]){
				re.pb(e.Y); re.pb(e.X); re.pb(rt); re.pb(n-1);
				yes(re);
			}
		}
		// for(int w:g[rt])if(w!=0){
		// 		re.pb(w);
		// 		re.pb(0);
		// 		re.pb(n-1);
		// 		yes(re);
		// 	}
		assert(0);
	}
  return 0;
}