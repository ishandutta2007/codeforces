#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define ll long long
#define lb(x) ((x)&(-x))
#define pii pair<int,int>
#define vi vector<int>
#define pb push_back
#define fi first
#define se second
#define de(x) cout<<x<<" x"<<endl
#define LCAFA rep(i,1,20)rep(j,1,n+1)fa[j][i]=fa[fa[j][i-1]][i-1]
#define all(x) x.begin(),x.end()
#define ls(x) x<<1
#define rs(x) x<<1|1
using namespace std;
const int N=2e5+9;
const ll mod=998244353;
int mini[N],b[N],cb[N],d[N],cnt;
ll seg[N<<2],lazy[N<<2];
pair<pii,int> mon[N];
pii a[N];
void pushup(int pos){
	seg[pos]=max(seg[ls(pos)],seg[rs(pos)]);
}
void pushdown(int pos){
	if(lazy[pos]){
		seg[ls(pos)]+=lazy[pos];
		seg[rs(pos)]+=lazy[pos];
		lazy[ls(pos)]+=lazy[pos];
		lazy[rs(pos)]+=lazy[pos];
		lazy[pos]=0;
	}
}
void build(int pos,int l,int r){
	if(l==r){
		seg[pos]=-mini[l];
		return;
	}
	int mid=l+r>>1;
	build(ls(pos),l,mid);
	build(rs(pos),mid+1,r);
	pushup(pos);
}
void upd(int pos,int L,int R,int l,int r,ll val){
	if(L<=l&&r<=R){
		lazy[pos]+=val;
		seg[pos]+=val;
		return;
	}
	pushdown(pos);
	int mid=l+r>>1;
	if(L<=mid)upd(ls(pos),L,R,l,mid,val);
	if(R>mid)upd(rs(pos),L,R,mid+1,r,val);
	pushup(pos);
}
int main(){
	int n,m,p;
	scanf("%d%d%d",&n,&m,&p);
	rep(i,0,n)scanf("%d%d",&a[i].fi,&a[i].se);
	rep(i,1,m+1)scanf("%d%d",&b[i],&cb[i]),d[++cnt]=b[i];
	rep(i,0,p){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		mon[i]={{x,y},z};
	} 
	sort(a,a+n);sort(mon,mon+p);
	sort(d+1,d+1+cnt);
	cnt=unique(d+1,d+1+cnt)-d-1;
	rep(i,1,cnt+1)mini[i]=1e9;
	rep(i,1,m+1)b[i]=lower_bound(d+1,d+1+cnt,b[i])-d,mini[b[i]]=min(mini[b[i]],cb[i]);
	build(1,1,cnt);
	ll ans=-1e18;
	//if(n==100)cout<<seg[1]<<endl;
	int num=0;
	rep(i,0,n){
		ll sum=-a[i].se;
		while(num<p&&mon[num].fi.fi<a[i].fi){
			int pos=upper_bound(d+1,d+1+cnt,mon[num].fi.se)-d;
			if(pos<=cnt)upd(1,pos,cnt,1,cnt,mon[num].se);
		//	if(n==100)cout<<cnt<<' '<<pos<<' '<<mon[num].fi.se<<' '<<seg[1]<<endl;
			++num;
		}
		sum+=seg[1];
		ans=max(sum,ans);
	}
	printf("%lld",ans);
}
/*
10 10 5
8 25067
5 287
6 8547
5 287
7 16807
8 25067
9 33327
9 33327
8 25067
5 287
5 287
7 16807
5 287
8 25067
7 16807
6 8547
5 287
7 16807
8 25067
9 33327
10 10 231653
10 10 13156
10 10 1236
10 10 131698
10 10 16168
*/