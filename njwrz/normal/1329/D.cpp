/*

DP





ll int
 dp 










*/
#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define ll long long
#define gmax(x,y) x=max(x,y)
#define gmin(x,y) x=min(x,y)
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB emplace_back
#define PF emplace_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
using namespace std;
int n;
class bit {
	public:
		int s[200005];
		void up(int p,int x) {
			while(p<=n) {
				s[p]+=x;
				p+=p&-p;
			}
		}
		int get(int p) {
			int re=0;
			while(p) {
				re=re+s[p];
				p-=p&-p;
			}
			RE re;
		}
		void clear() {
			FILL(s,0);
		}
} tree;
int a[200005],m,it[200005],c[200005],cnt[26];
set<int> s[26][26];
set<int> tot;
V<P<int,int> > tv;
void erase(int maxi,int i) {
	cnt[maxi]--;
	cnt[i]--;
	int it=*s[maxi][i].begin();
	s[maxi][i].erase(it);
	auto iter=tot.find(it);
	int tl=*iter;
	iter--;
	tv.PB(MP(*iter,tl));
	iter++;iter++;
	if(iter!=tot.end()) {
		int r=*iter;
		if(i!=c[r])s[i][c[r]].erase(r);
		iter--;
		iter--;
		if(iter!=tot.begin()) {
			iter--;
			int l=*iter;
			iter++;
			if(c[l]!=maxi)s[c[l]][maxi].erase(*iter);
			iter--;
			if(c[l]!=c[r])s[c[l]][c[r]].emplace(r);
		}
	} else {
		iter--;
		iter--;
		if(iter!=tot.begin()) {
			iter--;
			if(c[*iter]!=maxi) {
				s[c[*iter]][maxi].erase(*(++iter));
			}
		}
	}
	iter=tot.find(it);
	auto t1=iter;t1--;
	tot.erase(iter);
	tot.erase(t1);
}
V<P<int,int> > solve(int gg) {
	tv.clear();
	FILL(cnt,0);
	FOR(i,0,25) {
		FOR(j,0,25)s[i][j].clear();
	}
	tot.clear();
	FOR(i,1,m)cnt[c[i]]++;
	FOR(i,2,m)if(c[i-1]!=c[i])s[c[i-1]][c[i]].emplace(i);
	FOR(i,1,m)tot.emplace(i);
	while(1) {
		int maxi=0;
		FOR(i,1,25) {
			if(cnt[maxi]<cnt[i])maxi=i;
		}
		bool ff=0;
		rep(i,0,26) {
			if(!s[maxi][i].empty()) {
				erase(maxi,i);ff=1;break;
			}
			if(!s[i][maxi].empty()) {
				erase(i,maxi);ff=1;break;
			}
		}
		if(!ff) {
			while(!tot.empty()) {
				tv.PB(MP(*tot.begin(),0));
				tot.erase(tot.begin());
			}
			break;
		}
	}
	RE tv;
}
void solve() {
	string s;
	cin>>s;
	n=s.size();
	FOR(i,1,n)a[i]=s[i-1]-'a';
	m=0;
	FOR(i,2,n) {
		if(a[i]==a[i-1]) {
			c[++m]=a[i];
			it[m]=i-1;
		}
	}
	it[m+1]=n+1;
	V<P<int,int> > v=solve(m);
//	cout<<v.size()<<'\n';
//	for(auto u:v){
//		cout<<u.F<<' '<<u.S<<'\n';
//	}
	cout<<v.size()+1<<'\n';
	FOR(i,1,n)tree.s[i]=0;
	for(auto u:v) {
		if(u.S) {
			int t1,t2;
			t1=it[u.F]+1-tree.get(it[u.F]);
			t2=it[u.S]-tree.get(it[u.S]);
			cout<<t1<<' '<<t2<<'\n';
			tree.up(it[u.S],t2-t1+1);
		} else {
			int t1,t2;
			t1=1;
			t2=it[u.F]-tree.get(it[u.F]);
			cout<<t1<<' '<<t2<<'\n';
			tree.up(it[u.F],t2-t1+1);
		}
	}
	cout<<1<<' '<<n-tree.get(n)<<'\n';
}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
	RE 0;
}