//114514min
//ACM 
#include "bits/stdc++.h"
using namespace std;
template<typename typC,typename typD> istream &operator>>(istream &cin,pair<typC,typD> &a) { return cin>>a.first>>a.second; }
template<typename typC> istream &operator>>(istream &cin,vector<typC> &a) { for (auto &x:a) cin>>x; return cin; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const pair<typC,typD> &a) { return cout<<a.first<<' '<<a.second; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const vector<pair<typC,typD>> &a) { for (auto &x:a) cout<<x<<'\n'; return cout; }
template<typename typC> ostream &operator<<(ostream &cout,const vector<typC> &a) { int n=a.size(); if (!n) return cout; cout<<a[0]; for (int i=1; i<n; i++) cout<<' '<<a[i]; return cout; }
template<typename typC> bool cmin(typC &x,const typC &y) { if (x>y) { x=y; return 1; } return 0; }
template<typename typC> bool cmax(typC &x,const typC &y) { if (x<y) { x=y; return 1; } return 0; }
#if !defined(ONLINE_JUDGE)&&defined(LOCAL)
#include "my_header\debug.h"
#else
#define dbg(...) ;
#define dbgn(...) ;
#endif
typedef unsigned int ui;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
// void inc(ui &x,const ui &y) { if ((x+=y)>=p) x-=p; }
// void dec(ui &x,const ui &y) { if ((x+=p-y)>=p) x-=p; }
const int N=1e6+5;
template<typename typC> struct bit
{
	vector<typC> a;
	int n;
	bit() {}
	bit(int nn):n(nn),a(nn+1) {}
	template<typename T> bit(int nn,T *b):n(nn),a(nn+1)
	{
		for (int i=1; i<=n; i++) a[i]=b[i];
		for (int i=1; i<=n; i++) if (i+(i&-i)<=n) a[i+(i&-i)]+=a[i];
	}
	void add(int x,typC y)
	{
		//cerr<<"add "<<x<<" by "<<y<<endl;
		assert(1<=x&&x<=n);
		a[x]+=y;
		while ((x+=x&-x)<=n) a[x]+=y;
	}
	typC sum(int x)
	{
		//cerr<<"sum "<<x;
		assert(0<=x&&x<=n);
		typC r=a[x];
		while (x^=x&-x) r+=a[x];
		//cerr<<"= "<<r<<endl;
		return r;
	}
	typC sum(int x,int y)
	{
		return sum(y)-sum(x-1);
	}
};
template<typename T> struct tork
{
	vector<T> a;
	int n;
	tork(const vector<T> &b):a(all(b))
	{
		sort(all(a));
		a.resize(unique(all(a))-a.begin());
		n=a.size();
	}
	tork(const T *first,const T *last):a(first,last)
	{
		sort(all(a));
		a.resize(unique(all(a))-a.begin());
		n=a.size();
	}
	void get(T &x) { x=lower_bound(all(a),x)-a.begin()+1; }
	T operator[](const int &x) { return a[x]; }
};
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cout<<setiosflags(ios::fixed)<<setprecision(15);
	int n,i;
	cin>>n;
	vector<ll> a(n);
	cin>>a;
	for (i=1; i<n; i++) a[i]+=a[i-1];
	if (*min_element(all(a))<0||a[n-1]!=*max_element(all(a))) { cout<<"-1\n"; return 0; }
	tork s(a);
	for (ll &x:a) s.get(x);
	ll res=0;
	bit<int> t(n);
	reverse(all(a));
	for (ll x:a)  res+=t.sum(x-1),t.add(x,1);
	cout<<res<<endl;
}