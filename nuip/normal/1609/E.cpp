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
#define rep(X,Y) for (int X = 0;X < (int)(Y);++X)
#define reps(X,S,Y) for (int X = (int)(S);X < (int)(Y);++X)
#define rrep(X,Y) for (int X = (int)(Y)-1;X >=0;--X)
#define rreps(X,S,Y) for (int X = (int)(Y)-1;X >= (int)(S);--X)
#define repe(X,Y) for (X = 0;X < (Y);++X)
#define peat(X,Y) for (;X < (Y);++X)
#define all(X) X.begin(),X.end()
#define rall(X) X.rbegin(),X.rend()
#define eb emplace_back
#define UNIQUE(X) X.erase(unique(all(X)),X.end())
#define Endl endl
#define NL <<"\n"
#define cauto const auto

using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
template<class T> using vv=vector<vector<T>>;
template<class T> inline bool MX(T &l,const T &r){return l<r?l=r,1:0;}
template<class T> inline bool MN(T &l,const T &r){return l>r?l=r,1:0;}
//#undef NUIP
#ifdef NUIP
#include "benri.h"
#else
#define out(args...)
#endif
void ouT(ll x,int d=3){auto re=to_string(x);if((int)re.size()>d) re=x>0?"oo":"-oo";cout<<string(d-re.size(),' ')<<re<<",";}
#ifdef __cpp_init_captures
template<typename T>vector<T> table(int n, T v){ return vector<T>(n, v);}
template <class... Args> auto table(int n, Args... args){auto val = table(args...); return vector<decltype(val)>(n, move(val));}
#endif
template<class A,class B> pair<A,B> operator+(const pair<A,B> &p,const pair<A,B> &q){ return {p.X+q.X,p.Y+q.Y};}
template<class A,class B,class C,class D> pair<A,B>& operator+=(pair<A,B> &p,const pair<C,D> &q){ p.X+=q.X; p.Y+=q.Y; return p;}
template<class A,class B> pair<A,B> operator-(const pair<A,B> &p,const pair<A,B> &q){ return {p.X-q.X,p.Y-q.Y};}
template<class A,class B,class C,class D> pair<A,B>& operator-=(pair<A,B> &p,const pair<C,D> &q){ p.X-=q.X; p.Y-=q.Y; return p;}
template<class A,class B> istream& operator>>(istream &is, pair<A,B> &p){ is>>p.X>>p.Y; return is;}
template<class T=ll> T read(){ T re; cin>>re; return re;}
template<class T=ll> T read(const T &dec){ T re; cin>>re; return re-dec;}
template<class T=ll> vector<T> readV(const int sz){ vector<T> re(sz); for(auto &x:re) x=read<T>(); return re;}
template<class T=ll> vector<T> readV(const int sz, const T &dec){ vector<T> re(sz); for(auto &x:re) x=read<T>(dec); return re;}
vv<int> readG(const int &n,const int &m){ vv<int> g(n); rep(_,m){ cauto a=read<int>(1),b=read<int>(1); g[a].pb(b); g[b].pb(a);} return g;}
vv<int> readG(const int &n){ return readG(n,n-1);}
vv<int> readD(const int &n,const int &m){ vv<int> g(n); rep(_,m){ cauto a=read<int>(1),b=read<int>(1); g[a].pb(b); } return g;}
vv<int> readD(const int &n){ return readD(n,n-1);}
template<class T> vv<pair<int,T>> readG(const int &n,const int &m){ vv<pair<int,T>> g(n); rep(_,m){ cauto a=read<int>(1),b=read<int>(1); cauto c=read<T>(); g[a].eb(b,c); g[b].eb(a,c);} return g;}
template<class T> vv<pair<int,T>> readG(const int &n){ return readG<T>(n,n-1);}
template<class T> vv<pair<int,T>> readD(const int &n,const int &m){ vv<pair<int,T>> g(n); rep(_,m){ cauto a=read<int>(1),b=read<int>(1); cauto c=read<T>(); g[a].eb(b,c); } return g;}
template<class T> vv<pair<int,T>> readD(const int &n){ return readD<T>(n,n-1);}
#ifdef __cpp_deduction_guides
template<typename T> vector<T> readT(int n, T v){ return readV(n,v);}
template <class... Args> auto readT(int n, Args... args){ vector re(1,readT(args...));rep(_,n-1) re.eb(readT(args...));	return re;}
template<class Tuple, size_t... Is> void read_tuple_impl(istream &is, Tuple& t, index_sequence<Is...>){((is >> get<Is>(t)), ...);}
template<class... Args> auto& operator>>(istream &is, tuple<Args...>& t){ read_tuple_impl(is, t, index_sequence_for<Args...>{}); return is;}
template<class T> bool erase(multiset<T> &st, const T &v){if(cauto it=st.find(v); it==st.end()) return false; else{ st.erase(it); return true;}}
#endif
#ifdef __cpp_init_captures
template<typename T, size_t... Is> void addadd(T& t1, const T& t2, integer_sequence<size_t, Is...>){ cauto l = { (get<Is>(t1) += get<Is>(t2), 0)... }; (void)l;}
template <typename...T>tuple<T...>& operator += (tuple<T...>& lhs, const tuple<T...>& rhs){	addadd(lhs, rhs, index_sequence_for<T...>{});	return lhs;}
template <typename...T>tuple<T...> operator +(tuple<T...> lhs, const tuple<T...>& rhs){ return lhs += rhs;}
template<typename T, size_t... Is> void subsub(T& t1, const T& t2, integer_sequence<size_t, Is...>){ cauto l = { (get<Is>(t1) -= get<Is>(t2), 0)... }; (void)l;}
template <typename...T>tuple<T...>& operator -= (tuple<T...>& lhs, const tuple<T...>& rhs){	subsub(lhs, rhs, index_sequence_for<T...>{});	return lhs;}
template <typename...T>tuple<T...> operator - (tuple<T...> lhs, const tuple<T...>& rhs){ return lhs -= rhs;}
#endif
#define TT cauto TTT=read();rep(_,TTT)
struct sorted_impl{template<class T>friend vector<T>operator-(vector<T>a,sorted_impl){sort(all(a));return a;}friend string operator-(string a,sorted_impl){sort(all(a));return a;}}sorted;struct reversed_impl{template<class T>friend vector<T>operator-(vector<T> a,reversed_impl){reverse(all(a));return a;}friend string operator-(string a,reversed_impl){reverse(all(a));return a;}}reversed;struct distinct_impl{template<class T>friend vector<T>operator-(vector<T> a,distinct_impl){sort(all(a));UNIQUE(a);return a;}}distinct;template<class S>struct sortedWith{const S f;sortedWith(const S &f):f(f){}template<class T>friend vector<T>operator-(vector<T> a,const sortedWith&b){sort(all(a),[&](cauto&i,cauto&j){return b.f(i)<b.f(j);});return a;}};
template<class T>int operator/(const T&v,const vector<T>&vs){return lower_bound(all(vs),v)-vs.begin();}
vector<int> Inds(const int n){vector<int> inds(n);iota(all(inds),0);return inds;}
const ll MOD=1e9+7; //998244353;

struct Seg{
	int a,b,c,ab,bc,abc;
	Seg():a(0),b(0),c(0),ab(0),bc(0),abc(0){};
	Seg(int a,int b,int c,int ab,int bc,int abc):a(a),b(b),c(c),ab(ab),bc(bc),abc(abc){};
  static Seg e;
};
ostream& operator<<(ostream &os, const Seg &t){
	return os<<"("<<t.a<<","<<t.b<<","<<t.c<<", "<<t.ab<<","<<t.bc<<", "<<t.abc<<")";
}
Seg Seg::e=Seg();

Seg operator+(const Seg &l,const Seg &r){
  Seg re(l.a+r.a, l.b+r.b, l.c+r.c,
				 min(l.a+r.ab, l.ab+r.b),
				 min(l.b+r.bc, l.bc+r.c),
				 min({l.a+r.abc, l.ab+r.bc, l.abc+r.c}));
	MN(re.ab, re.a);
	MN(re.ab, re.b);
	MN(re.bc, re.b);
	MN(re.bc, re.c);
	MN(re.abc, re.ab);
	MN(re.abc, re.bc);
	return re;
}
const Seg a(1,0,0,0,0,0);
const Seg b(0,1,0,0,0,0);
const Seg c(0,0,1,0,0,0);


template<class SegTree>
struct SegTreeUpdater{
	SegTree *st;
	int i;
	SegTreeUpdater(SegTree *st,int i):st(st),i(i){}
	template<class Seg> void operator+=(const Seg &seg){ st->add(i,seg);}
	template<class Seg> void operator=(const Seg &seg){	st->assign(i,seg);}
};

template<class Seg>
struct SegTree{
	vector<Seg> segs;
	void add(int k,Seg a){
		k+=segs.size()/2-1;
		segs[k]=segs[k]+a;
		upd(k);
	}
	void assign(int k,Seg a){
		k+=segs.size()/2-1;
		segs[k]=a;
		upd(k);
	}
	void upd(int k){
		while(k>0){
			k=(k-1)/2;
			segs[k]=segs[k*2+1]+segs[k*2+2];
		}
	}
	void upd(){	rrep(k,segs.size()/2-1) segs[k]=segs[k*2+1]+segs[k*2+2];}
	
	//(l,r,0,0,nn)
	template<class T=Seg> T query(int a,int b,int k,int l,int r){
		if(r<=a || b<=l)return T::e;
		if(a<=l && r<=b) return segs[k];
		T lv=query(a,b,k*2+1,l,(l+r)/2) ,rv= query(a,b,k*2+2,(l+r)/2,r);
		return lv+rv;
	}

	SegTree(int n){
		int pw=1;
		while(pw<n) pw*=2;
		segs.resize(2*pw);
	}
	SegTreeUpdater<SegTree<Seg>> operator[](int i){ return {this,i};}
	Seg operator()(int l,int r){ return query(max(0,l),min((int)segs.size()/2,r),0,0,segs.size()/2);};
	Seg& operator()(int i){ return segs[segs.size()/2-1+i];}
	Seg operator()(){ return segs[0];}
	Seg rb(int r){ return operator()(0,r); }
	Seg lb(int l){ return operator()(l,segs.size()/2); }
};

int naive(const string &s){
	const int n=s.size();
	auto dp=table(n+1,3,MOD);
	dp[0]={0,0,0};
	rep(i,n){
		rep(j,3) MN(dp[i+1][j],dp[i][j]+(s[i]=='a'+j));
		rep(j,2) MN(dp[i+1][j+1],dp[i+1][j]);
	}
	return dp[n][2];
}

Seg solve(const string &s){
	Seg seg;
	for(cauto &x:s) seg=seg+(x=='a'?a:x=='b'?b:c);
	return seg;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	cout<<fixed<<setprecision(0);
#ifdef NUIP
	reps(n,1,5){
		out(n,1);
		vector<string> ss{""};
		rep(_,n){
			cauto tmp=ss;
			for(cauto &s:tmp){
				ss.eb(s+"a");
				ss.eb(s+"b");
				ss.eb(s+"c");
			}
		}
		for(cauto &a:ss)for(cauto &b:ss){
				cauto exp=solve(a+b);
				cauto act=solve(a)+solve(b);
				if(exp.a!=act.a ||
					 exp.b!=act.b ||
					 exp.c!=act.c ||
					 exp.ab!=act.ab ||
					 exp.bc!=act.bc ||
					 exp.abc!=act.abc){
					out(exp,act,a,b,1);
					return 0;
				}
			}
	}
	reps(n,1,20){
		out(n,1);
		vector<string> ss{""};
		rep(_,n){
			vector<string> nxt;
			for(cauto &s:ss){
				nxt.eb(s+"a");
				nxt.eb(s+"b");
				nxt.eb(s+"c");
			}
			ss=nxt;
		}
		const int N=ss.size();
		vector<int> dst(N,MOD);
		queue<int> que;
		rep(i,N){
			cauto &s=ss[i];
			int ok=1;
			rep(c,s.size())rep(b,c)rep(a,b)if(s[a]=='a' && s[b]=='b' && s[c]=='c') ok=0;
			if(!ok) continue;
			dst[i]=0;
			que.emplace(i);
		}
		while(que.size()){
			cauto i=que.front(); que.pop();
			cauto s=ss[i];
			rep(j,s.size())rep(k,3){
				auto t=s;
				t[j]='a'+k;
				cauto ind=lower_bound(all(ss),t)-ss.begin();
				if(MN(dst[ind],dst[i]+1)) que.emplace(ind);
			}
		}
		rep(i,N){
			cauto exp=dst[i];
			cauto act=solve(ss[i]).abc;
			if(exp!=act){
				out(exp,act,ss[i],1);
				return 0;
			}
		}
	}
	return 0;
	{
		rep(_,100000){
			cauto n=rand()%100+1;
			string s(n,'a');
			for(auto &c:s) c+=rand()%3;
			cauto exp=naive(s);
			cauto act=solve(s).abc;
			if(exp!=act){
				out(exp,act,s,1);
				return 0;
			}
		}
		return 0;
	}
#endif
	cauto n=read();
	cauto q=read();
	cauto s=read<string>();
	cauto qs=readV(q,pair(1,'\0'));
	SegTree<Seg> st(n);
	rep(i,n) st[i]=(s[i]=='a'?a:s[i]=='b'?b:c);
	for(cauto &[i,d]:qs){
		st[i]=(d=='a'?a:d=='b'?b:c);
		cout<<st().abc NL;
	}
	return 0;
}