#include <bits/stdc++.h>
using namespace std;
  
#define rep(i,a,n) for (int i=(a);i<(n);i++)
#define per(i,a,n) for (int i=(a)-1;i>=(n);i--)
#define pb push_back
#define all(x) x.begin(),x.end()
#define SZ(x) (int)x.size()
#define fi first
#define se second
#define bug(x) cerr<<#x<<'='<<x<<' '
#define debug(x) cerr<<#x<<'='<<x<<endl

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int N=205;
int n,m;
ll k;

int ans[205];
ll cnt;

namespace KMP {
	static const int M=205;
	int e[M][2],fail[M],tot;
	int mark[M];
	int que[M],l,r;
	
	int newnod() {
		++tot;
		e[tot][0]=e[tot][1]=0;
		mark[tot]=fail[tot]=0;
		return tot;
	}
	void clear() {
		tot=-1,tot=newnod();
	}
	void insert() {
		int cur=0;
		rep(i,1,cnt+1) {
			int &tmp=e[cur][ans[i]];
			if (!tmp) tmp=newnod();
			cur=tmp;
		}
		mark[cur]=1;
	}
	void init() {
		l=1,r=0;
		rep(i,0,2) if (e[0][i]) que[++r]=e[0][i];
		while (l<=r) {
			int u=que[l++];
			rep(i,0,2) {
				int &tmp=e[u][i];
				if (tmp) que[++r]=tmp,fail[tmp]=e[fail[u]][i];
				else tmp=e[fail[u]][i];
			}		
		}
	}
}
using namespace KMP;

struct node {
	bitset<N> pre,suf;
	ll len;
	node() {len=0;}
	void pt() {
		cout<<pre.to_string()<<' ';
		cout<<suf.to_string()<<endl;	
	}
}f[205];

int mx=201;
node operator +(node a,node b) {
	node tmp;
	tmp.len=a.len+b.len;
	// tmp.pre=a.pre,tmp.suf=b.suf;
	
	if (a.len>=mx) tmp.pre=a.pre;
	else if (tmp.len<=mx) tmp.pre=(a.pre<<b.len)|b.pre;
	else {
		ll c=mx-a.len;
		tmp.pre=(a.pre<<c)|(b.pre>>(min((ll)mx,b.len)-c));
	}
	
	if (b.len>=mx) tmp.suf=b.suf;
	else if (tmp.len<=mx) tmp.suf=(a.suf<<b.len)|b.suf;
	else tmp.suf=(a.suf<<b.len)|b.suf;
	
	if (tmp.len>=1e18) tmp.len=1e18;
	return tmp;
}
ll operator ^(node a,node b) {
	int cur=0,res=0;
	for (int i=min(a.len-1,cnt-2);i>=0;i--) cur=e[cur][a.suf[i]];
	
	for (int i=min((ll)mx-1,b.len-1),l=1;i>=0&&l<cnt;l++,i--) {
		cur=e[cur][b.pre[i]];
		if (mark[cur]) res++;
	}
	return res;
}
bool check() {//
	rep(i,1,cnt+1) if (ans[i]!=f[n].suf[cnt-i]) return 0;
	return 1;
}

ll g[205];
ll gao() {
	// ans[1..cnt]
	// kmp_init
	clear();
	insert();
	init();
	
	g[0]=g[1]=0;
	if (cnt==1&&ans[1]==0) g[0]=1;
	if (cnt==1&&ans[1]==1) g[1]=1;
	rep(i,2,n+1) {
		g[i]=(f[i-2]^f[i-1])+g[i-2]+g[i-1];
		if (g[i]>1e18) g[i]=1e18;
	}
	return g[n];
}
void prt() {
	rep(i,1,cnt+1) printf("%d",ans[i]); puts("");
}
void solve() {
	f[0].pre=0,f[0].suf=0,f[0].len=1;
	f[1].pre=1,f[1].suf=1,f[1].len=1;
	rep(i,2,n+1) f[i]=f[i-2]+f[i-1];
	
	rep(i,1,m+1) {
		if (!k) return;
		ans[++cnt]=0;
		ll b=gao();
		// bug(i),bug(k);
		// prt();
		// debug(b);
		if (b>=k) ;
		else if (b<k) {
			ans[cnt]=1;
			k-=b;
		}
		if (check()) k--;
	}
}

int main() {
	cin>>n>>k>>m;
	solve();
	rep(i,1,cnt+1) printf("%d",ans[i]);
	puts("");
	return 0;	
}