#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define ll long long
#define ls pos<<1
#define rs pos<<1|1
#define lb(x) ((x)&(-x))
using namespace std;
const int N=2e5+9;
const ll mod=998244353;
ll tree[N<<2],mul[N<<2],inv[101],p[N],sum[N];
void pushup(int pos){
	tree[pos]=tree[ls]+tree[rs];
	if(tree[pos]>=mod)tree[pos]-=mod;
}
void pushdown(int pos){
	if(mul[pos]^1){
		tree[ls]=tree[ls]*mul[pos]%mod;
		tree[rs]=tree[rs]*mul[pos]%mod;
		mul[ls]=mul[ls]*mul[pos]%mod;
		mul[rs]=mul[rs]*mul[pos]%mod;
		mul[pos]=1;
	}
}
void build(int l,int r,int pos){
	mul[pos]=1;
	if(l==r){
		tree[pos]=sum[l];
		return;
	}
	int mid=l+r>>1;
	build(l,mid,ls);
	build(mid+1,r,rs);
	pushup(pos);
}
void upd(int l,int r,int L,int R,int pos,int val){
	if(L<=l&&r<=R){
		mul[pos]=mul[pos]*val%mod;
		tree[pos]=tree[pos]*val%mod;
		return;
	}
	pushdown(pos);
	int mid=l+r>>1;
	if(L<=mid)upd(l,mid,L,R,ls,val);
	if(R>mid)upd(mid+1,r,L,R,rs,val);
	pushup(pos);
}
ll get(int p,int l,int r,int pos){
	if(l==r)return tree[pos];
	pushdown(pos);
	int mid=l+r>>1;
	if(p<=mid)return get(p,l,mid,ls);
	return get(p,mid+1,r,rs);
}
ll quick(ll a,ll b){
	ll res=1;
	while(b){
		if(b&1)res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}
void pre(){
	inv[0]=inv[1]=1;
	rep(i,2,101){
		int k=mod/i,r=mod%i;
		inv[i]=-k*inv[r]%mod;
		inv[i]+=mod;
	}
}
int tot[N],vis[N];
void Set(int n,int val){
	for(int i=n;i<N;i+=lb(i))tot[i]+=val;
}
int Get(int n){
	int res=0;
	for(int i=n;i;i^=lb(i))res+=tot[i];
	return res;
}
int find(int u){
	int val=Get(u),l=1,r=u;
	while(l<r){
		int mid=l+r>>1;
		if(Get(mid)>=val)r=mid;
		else l=mid+1;
	}
	return r;
}
set<int> S;
int main(){
	pre();
	int q,n;
	scanf("%d%d",&n,&q);
	rep(i,1,n+1)scanf("%lld",&p[i]);
	sum[n+1]=1;
	per(i,1,n+1)sum[i]=sum[i+1]*100%mod*inv[p[i]]%mod;
	build(1,n,1);
	S.insert(1);
	vis[1]=1;
//	rep(i,1,n+1)cout<<get(i,1,n,1)<<"check\n";;
//	cout<<(15+71*quick(3,mod-2)%mod)<<"??????\n";
	while(q--){
		int u;
		scanf("%d",&u);
		if(vis[u]){
			ll val=get(u,1,n,1);
			auto it=S.find(u);
			--it;
			int pos=*it;
			upd(1,n,pos,u-1,1,val);
			S.erase(u);
			vis[u]=0;
		}
		else{
			ll val=get(u,1,n,1);
			val=quick(val,mod-2);
			S.insert(u);
			auto it=S.find(u);
			--it;
			int pos=*it;
			upd(1,n,pos,u-1,1,val);
			vis[u]=1;
		}
		printf("%lld\n",tree[1]);
	//	rep(i,1,n+1)cout<<get(i,1,n,1)<<"check\n";;
	//	system("pause");
	}
}
/*
2 2100
50 50
2
2
*/