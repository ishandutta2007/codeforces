#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
typedef pair<int,int> pii;
#define ls (x<<1)
#define rs (x<<1|1)
#define mp make_pair
#define fi first
#define se second
#define pb push_back

int n,q,k,now=1,fa[N],siz[N],ans[N],tt,op[N][3],day[N];
vector<pii> vec[N<<2];
pii qry[N];

struct dat {
	int x,y,siz;
};

int getf(int x) {
	return x==fa[x]?x:getf(fa[x]);
}

void merge(int x,int y,vector<dat> &mem) {
	x=getf(x);y=getf(y);
	if(x==y) return;
	if(siz[x]>siz[y]) swap(x,y);
	mem.pb((dat){x,y,siz[y]});
	fa[x]=y;siz[y]+=siz[x];
}

void insert(int L,int R,pii e,int x=1,int l=1,int r=q) {
	if(L<=l&&r<=R) { vec[x].pb(e);return; }
	int mid=(l+r)>>1;
	if(L<=mid) insert(L,R,e,ls,l,mid);
	if(R>mid) insert(L,R,e,rs,mid+1,r);
}	

void solve(int x=1,int l=1,int r=q) {
	vector<dat> mem;
	for(auto e:vec[x]) merge(e.fi,e.se,mem);
	if(l==r) {
		if(qry[l].fi) ans[qry[l].fi]=siz[getf(qry[l].se)];
	}
	else {
		int mid=(l+r)>>1;
		solve(ls,l,mid);solve(rs,mid+1,r);
	}
	reverse(mem.begin(),mem.end());
	for(auto t:mem) fa[t.x]=t.x,siz[t.y]=t.siz;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>q>>k;
	for(int i=1;i<=n;i++) fa[i]=i,siz[i]=1;
	for(int i=1;i<=q;i++) {
		cin>>op[i][0];day[i]=day[i-1];
		for(int j=1;j<=3-op[i][0];j++) cin>>op[i][j];
		if(op[i][0]==2) qry[i]=mp(++tt,op[i][1]);
		if(op[i][0]==3) ++day[i];
	}
	for(int i=1;i<=q;i++)
		if(op[i][0]==1) {
			int t=lower_bound(day+1,day+q+1,day[i]+k)-day;
			insert(i,t-1,mp(op[i][1],op[i][2]));
		}
	solve();
	for(int i=1;i<=tt;i++) cout<<ans[i]<<'\n';
	return 0;
}