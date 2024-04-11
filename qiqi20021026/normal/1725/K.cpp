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
int a[N];
set<int>::iterator bg[N];

struct cmp
{
	bool operator()(const set<int>::iterator &x,const set<int>::iterator &y) const
	{
		return &*x<&*y;
	}
};
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cout<<setiosflags(ios::fixed)<<setprecision(15);
	int n,i;
	cin>>n;
	map<int,set<int>> pos;
	map<set<int>::iterator,int,cmp> tv;
	auto insert=[&](int k,int w)
	{
		if (!pos.count(w))
		{
			pos[w]={0,k};
			bg[k]=pos[w].begin();
			tv[bg[k]]=w;
		}
		else pos[w].insert(k),bg[k]=pos[w].begin();
		return;
	};
	auto merge=[&](int x,int y)
	{
		set<int> &fx=pos[x];
		set<int> &fy=pos[y];
		if (!fx.size()) fx={0},tv[fx.begin()]=x;
		if (!fy.size()) fy={0},tv[fy.begin()]=y;
		if (fx.size()<fy.size()) swap(fx,fy);
		tv[fx.begin()]=x;
		tv.erase(fy.begin());
		for (int x:fy) if (x) fx.insert(x),bg[x]=fx.begin();
	};
	for (i=1; i<=n; i++)
	{
		cin>>a[i];
		insert(i,a[i]);
	}
	auto askh=[&](int id)
	{
		return tv[bg[id]];
	};
	int q;
	cin>>q;
	while (q--)
	{
		int op;
		cin>>op;
		// dbgn(op);
		// for (i=1; i<=n; i++) askh(i);
		if (op==1)
		{
			int k,w;
			cin>>k>>w;
			int h=askh(k);
			pos[h].erase(k);
			if (pos[h].size()==1)
			{
				tv.erase(pos[h].begin());
				pos.erase(h);
			}
			insert(k,w);
		}
		else if (op==2)
		{
			int k;
			cin>>k;
			cout<<askh(k)<<'\n';
		}
		else
		{
			int l,r;
			cin>>l>>r;
			auto lt=pos.lower_bound(l);
			auto it=lt;
			int mid=l+r>>1;
			for (; it!=pos.end()&&it->first<=r; ++it)
			{
				if (it->first<=mid) merge(l-1,it->first);
				else merge(r+1,it->first);
			}
			pos.erase(lt,it);
		}
	}
}