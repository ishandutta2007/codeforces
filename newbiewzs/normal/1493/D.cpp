#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int ksm(int x,int k){
	int base=1;
	while(k){
		if(k&1)base=1ll*base*x%mod;
		x=1ll*x*x%mod;
		k>>=1;
	}
	return base;
}
const int N=2e5+55;
int tot;
int ch[N*100][2],minn[N*100];
struct heap{
	int rt;
	#define ls ch[u][0]
	#define rs ch[u][1]
	#define mid ((l+r)>>1)
	void update(int u){
		if(!ch[u][0])minn[u]=0;
		else if(!ch[u][1])minn[u]=0;
		else minn[u]=min(minn[ls],minn[rs]);
	}
	void add(int &u,int l,int r,int x,int k){
		if(!u)u=++tot;
		if(l==r){
			minn[u]+=k;
			return ;
		}
		if(x<=mid)add(ls,l,mid,x,k);
		else add(rs,mid+1,r,x,k);
		update(u);
	}
}h[N];
int n,a[N],vis[N];
int st[N],top,x,y;
void init(){
	for(int i=2;i<N;i++){
		if(!vis[i])st[++top]=i;
		for(int k=1;st[k]*i<N and k<=top;k++){
			vis[st[k]*i]=1;
			if(i%st[k]==0)break;
		}
	}
}
int qq;
int mul[N*8];
#define lc (u<<1)
#define rc (u<<1|1)
void build(int u,int l,int r){
	if(l==r){
		mul[u]=1;
		return ;
	}
	build(lc,l,mid);
	build(rc,mid+1,r);
	mul[u]=1;
}
void add(int u,int l,int r,int x,int k){
	if(l==r){
		mul[u]=ksm(x,k);
		return ;
	}
	if(x<=mid)add(lc,l,mid,x,k);
	else add(rc,mid+1,r,x,k);
	mul[u]=1ll*mul[lc]*mul[rc]%mod;
}
vector<int>v[N],jl[N];
int pd[N];
int main(){
//	freopen("data.in","r",stdin);
//	freopen("s.out","w",stdout);
	init();
	scanf("%d",&n);
	scanf("%d",&qq);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		x=a[i];int xx=a[i];
	//	printf("%d\n",i);
		if(pd[xx]){
			for(int j=0;j<v[xx].size();j++){
				int k=v[xx][j];
				int cs=jl[xx][j];
				if(cs)h[k].add(h[k].rt,1,n,i,cs);
			}
			continue;
		}
		for(int k=1;st[k]<=xx;k++){
			int cs=0;
			while(x%st[k]==0){
				cs++;
				x/=st[k];
			}
			if(cs){
				v[xx].push_back(k);
				jl[xx].push_back(cs);
				pd[xx]=1;
				h[k].add(h[k].rt,1,n,i,cs);
			}
			if(x==1)break;
		}
	}
	build(1,1,N);
	int ans=0;
	for(int k=1;k<=top;k++){
		if(h[k].rt){
			add(1,1,N,st[k],minn[h[k].rt]);
		}
	}
	for(int i=1;i<=qq;i++){
		scanf("%d%d",&x,&y);
		swap(x,y);
		int xx=x;
		if(pd[xx]){
			for(int j=0;j<v[xx].size();j++){
				int k=v[xx][j];
				int cs=jl[xx][j];
				h[k].add(h[k].rt,1,n,y,cs);
				if(h[k].rt){
					add(1,1,N,st[k],minn[h[k].rt]);
				}
			}
			printf("%d\n",mul[1]);
			continue;
		}
		for(int k=1;st[k]<=xx;k++){
			int cs=0;
			while(x%st[k]==0){
				cs++;
				x/=st[k];
			}
			if(cs){
				v[xx].push_back(k);
				jl[xx].push_back(cs);
				pd[xx]=1;
				h[k].add(h[k].rt,1,n,y,cs);
				if(h[k].rt){
					add(1,1,N,st[k],minn[h[k].rt]);
				}
			}
			if(x==1 || x==0)break;
		}
		printf("%d\n",mul[1]);
	}
	return 0;
}