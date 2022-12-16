#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <algorithm>
#include <iostream>
#define MN 2000
#define set(id,u,v,c) nxt[id]=hd[u],hd[u]=id,to[id]=v,cap[id]=c
int n1,n2,m,k;
bool flag,sped=false,usd[MN*2+5];
int ans[MN*MN+5],ansc=0;
int r[2*MN+5],d[2*MN+5],mind=LONG_MAX;
int hd[2*MN+5],to[2*MN+5],nxt[2*MN+5],cap[2*MN+5];
void flow(int u){
	usd[u]=true;
	if(u>n1&&r[u]<d[u]-k){
		flag=true;
		r[u]++;
		usd[u]=false;
		return;
	}
	for(int i=hd[u];i!=-1;i=nxt[i]){
		if(usd[to[i]])continue;
		if(cap[i]==0)continue;
		cap[i]=0,cap[i^1]=1;
		flow(to[i]); if(flag)break;
		cap[i]=1,cap[i^1]=0;
	}
}
int main(){
	memset(hd,0xff,sizeof(hd));
	scanf("%d%d%d",&n1,&n2,&m);
	if(n1<n2)std::swap(n1,n2),sped=true;
	for(int i=1;i<=m;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		if(sped)std::swap(u,v);
		v+=n1;
		d[u]++,d[v]++;
		set(i<<1,u,v,1);
		set(i<<1|1,v,u,0);
	}
	for(int i=1;i<=n1+n2;i++)
		mind=std::min(mind,d[i]);
	for(k=mind;k>=1;k--){
		for(int i=1;i<=n1;i++){
			if(k==mind)
				for(int j=1;j<=d[i]-k;j++){
					flag=false;
					memset(usd,false,sizeof(usd));
					flow(i);
				}
			else{
				flag=false;
				memset(usd,false,sizeof(usd));
				flow(i);
			}
		}
		for(int i=1;i<=m;i++)
			if(cap[i<<1]==1)
				ans[++ansc]=i;
	}
	for(int k=0;k<=mind;k++){
		printf("%d ",k*std::max(n1,n2));
		for(int i=1;i<=k*std::max(n1,n2);i++)
			printf("%d ",ans[ansc--]);
		printf("\n");
	}
}