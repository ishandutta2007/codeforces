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
const int N=2e6+9;
const ll mod=998244353;
int n,pos[N],p[N],q[N],maxn[N<<2],lazy[N<<2];
void pushdown(int pos){
	maxn[ls(pos)]+=lazy[pos];
	maxn[rs(pos)]+=lazy[pos];
	lazy[ls(pos)]+=lazy[pos];
	lazy[rs(pos)]+=lazy[pos];
	lazy[pos]=0;
}
void pushup(int pos){
	maxn[pos]=max(maxn[ls(pos)],maxn[rs(pos)]);
}
void add(int pos,int l,int r,int L,int R,int val){
	while(L<=l&&r<=R){
		maxn[pos]+=val;
		lazy[pos]+=val;
		return;
	}
	if(lazy[pos])pushdown(pos);
	int mid=l+r>>1;
	if(L<=mid)add(ls(pos),l,mid,L,R,val);
	if(R>mid)add(rs(pos),mid+1,r,L,R,val);
	pushup(pos);
}
int main(){
	scanf("%d",&n);
	rep(i,1,n+1)scanf("%d",&p[i]),pos[p[i]]=i;
	rep(i,1,n+1)scanf("%d",&q[i]);
	int ans=n;
	add(1,1,n,1,pos[n],1);
	printf("%d ",ans);
	rep(i,1,n){
		add(1,1,n,1,q[i],-1);
		while(maxn[1]<=0){
			--ans;
			add(1,1,n,1,pos[ans],1);
		}
		printf("%d ",ans);
	}
}