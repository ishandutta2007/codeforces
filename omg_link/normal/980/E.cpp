#include <stdio.h>
#include <string.h>
#define MN 1000000
int n,k;
int f[MN+5],hd[MN+5],to[MN*2+5],nxt[MN*2+5],rn=0;
int st[MN+5],ed[MN+5],d[MN+5],an=0,tag[MN*4+5];
bool rem[MN+5];
void add(int u,int v){
	++rn; 
	nxt[rn]=hd[u],hd[u]=rn; 
	to[rn]=v;
}
void make(int u,int de){
	++an; st[u]=an,d[u]=de;
	for(int i=hd[u];i!=-1;i=nxt[i]){
		if(to[i]==f[u])continue;
		f[to[i]]=u; make(to[i],de+1);
	}
	ed[u]=an;
}
void pushdown(int k){
	tag[k<<1]+=tag[k];
	tag[k<<1|1]+=tag[k];
	tag[k]=0;
}
void updata(int k,int l,int r,int tl,int tr,int tx){
	if(l==tl&&r==tr){tag[k]+=tx;return;}
	int mid=(l+r)>>1; pushdown(k);
	if(tr<=mid){updata(k<<1,l,mid,tl,tr,tx);return;}
	if(tl>mid){updata(k<<1|1,mid+1,r,tl,tr,tx);return;}
	updata(k<<1,l,mid,tl,mid,tx);
	updata(k<<1|1,mid+1,r,mid+1,tr,tx);
}
int query(int k,int l,int r,int p){
	if(l==r){return d[p]+tag[k];}
	int mid=(l+r)>>1; pushdown(k);
	if(st[p]<=mid)return query(k<<1,l,mid,p);
	else return query(k<<1|1,mid+1,r,p);
}
int main(){
	scanf("%d%d",&n,&k); k=n-k;
	memset(hd,0xff,sizeof(hd));
	for(int i=1;i<=n-1;i++){
		int u,v; scanf("%d%d",&u,&v);
		add(u,v),add(v,u);
	}
	memset(f,0xff,sizeof(f));
	memset(d,0x7f,sizeof(d));
	memset(tag,0,sizeof(tag));
	f[n]=n; make(n,0);
	memset(rem,true,sizeof(rem)); 
	rem[n]=false; k--;
	for(int i=n-1;k!=0;i--){
		if(!rem[i])continue;
		int dep=query(1,1,n,i);
		if(dep<=k){
			k-=dep;
			for(int j=i;rem[j];j=f[j]){
				rem[j]=false;
				updata(1,1,n,st[j],ed[j],-1);
			}
		}
	}
	for(int i=1;i<=n;i++)
		if(rem[i])printf("%d ",i);
}