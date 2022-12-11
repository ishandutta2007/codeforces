#include<bits/stdc++.h>
#define N 200010
using namespace std;
int n,m,k,i,x,y,h[N],t;
long long ans,Ans,g[N],f[N];
struct mjj{int x,y,z;}a[N];
bool cmp(mjj a,mjj b){return a.x<b.x;}
int main() {
	scanf("%d%d%d",&n,&m,&k);
	for(i=1;i<=m;i++){
		scanf("%d%d%d%d",&a[i].x,&x,&y,&a[i].z);
		if(x==0)a[i].y=y;
		else a[i].y=-x;
	}
	Ans=0; 
	Ans=1e18;
	sort(a+1,a+m+1,cmp);
	for(i=1;i<=m;i++)h[i]=a[i].x;
	for(i=1;i<=n;i++)f[i]=1e12,ans+=f[i];
	g[0]=1e18;
	for(i=1;i<=m;i++)if(a[i].y<0){
		ans-=f[-a[i].y];
		f[-a[i].y]=min(f[-a[i].y],1ll*a[i].z);
		ans+=f[-a[i].y];
		g[i]=ans;
	}else g[i]=g[i-1];
	memset(f,63,sizeof(f));
	ans=0;
	for(i=1;i<=n;i++)f[i]=1e12,ans+=f[i];
	for(i=m;i>=1;i--)if(a[i].y>0){
		ans-=f[a[i].y];
		f[a[i].y]=min(f[a[i].y],1ll*a[i].z);
		ans+=f[a[i].y];
		t=lower_bound(h+1,h+m+1,a[i].x-k)-h-1;
		if(t)Ans=min(Ans,ans+g[t]);
	}
	if(Ans>=1e12)puts("-1");
	else printf("%I64d\n",Ans);
}