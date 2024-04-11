#include<bits/stdc++.h>
using namespace std;

const int inf=1000000000;
int po[5],p[5],dir[5],x[5],y[5],T,ans,ansx[5],ansy[5],nwx[5],nwy[5],nw,len;
bool bo[5];

int getdis(int x,int y,int X,int Y) {return (x<X?X-x:x-X)+(y<Y?Y-y:y-Y);}

void check()
{
	len=-1;
	for (int i=0; i<4; i++) po[p[i]]=i;
	for (int i=0; i<4; i++)
	{
		if (dir[po[i]]==0) nwx[i]=x[po[i]],nwy[i]=-inf;
		else nwx[i]=-inf,nwy[i]=y[po[i]];
	}
	if (nwx[0]!=-inf&&nwx[1]!=-inf)
	{
		if (nwx[1]<=nwx[0]) return;
		if (len!=-1&&len!=nwx[1]-nwx[0]) return;
		len=nwx[1]-nwx[0];
	}
	if (nwy[1]!=-inf&&nwy[2]!=-inf)
	{
		if (nwy[1]<=nwy[2]) return;
		if (len!=-1&&len!=nwy[1]-nwy[2]) return;
		len=nwy[1]-nwy[2];
	}
	if (nwx[2]!=-inf&&nwx[3]!=-inf)
	{
		if (nwx[2]<=nwx[3]) return;
		if (len!=-1&&len!=nwx[2]-nwx[3]) return;
		len=nwx[2]-nwx[3];
	}
	if (nwy[3]!=-inf&&nwy[0]!=-inf)
	{
		if (nwy[0]<=nwy[3]) return;
		if (len!=-1&&len!=nwy[0]-nwy[3]) return;
		len=nwy[0]-nwy[3];
	}
	if (len==-1)
	{
		if (nwx[0]!=-inf)
		{
			nwy[0]=nwy[1];
			nwx[1]=nwx[2];
			nwy[2]=nwy[3];
			nwx[3]=nwx[0];
		} else
		{
			nwx[0]=nwx[3];
			nwy[3]=nwy[2];
			nwx[2]=nwx[1];
			nwy[1]=nwy[0];
		}
		len=nwx[1]-nwx[0];
	} else
	{
		int pp=-1;
		if (nwx[0]!=-inf)
		{
			if (nwy[1]!=-inf) nwy[0]=nwy[1],pp=0; else
			if (nwy[3]!=-inf) nwx[3]=nwx[0],pp=3; else
			nwy[3]=nwy[2],pp=3;
		} else
		{
			if (nwx[1]!=-inf) nwy[1]=nwy[0],pp=1; else
			if (nwx[3]!=-inf) nwx[0]=nwx[3],pp=0; else
			nwx[1]=nwx[2],pp=1;
		}
		if (pp==1) 
		{
			if (nwx[0]!=-inf&&nwx[0]!=nwx[1]-len) return;
			if (nwy[0]!=-inf&&nwy[0]!=nwy[1]) return;
			nwx[0]=nwx[1]-len,nwy[0]=nwy[1];
		}
		if (pp==3) 
		{
			if (nwx[0]!=-inf&&nwx[0]!=nwx[3]) return;
			if (nwy[0]!=-inf&&nwy[0]!=nwy[3]+len) return;
			nwx[0]=nwx[3],nwy[0]=nwy[3]+len;
		}
		if (nwx[1]!=-inf&&nwx[1]!=nwx[0]+len) return;
		if (nwy[1]!=-inf&&nwy[1]!=nwy[0]) return;
		if (nwx[2]!=-inf&&nwx[2]!=nwx[0]+len) return;
		if (nwy[2]!=-inf&&nwy[2]!=nwy[0]-len) return;
		if (nwx[3]!=-inf&&nwx[3]!=nwx[0]) return;
		if (nwy[3]!=-inf&&nwy[3]!=nwy[0]-len) return;
		nwx[1]=nwx[0]+len,nwy[1]=nwy[0];
		nwx[2]=nwx[0]+len,nwy[2]=nwy[0]-len;
		nwx[3]=nwx[0],nwy[3]=nwy[0]-len;
	}
	if (len<0) return;
	if (nwx[1]-nwx[0]!=len||nwy[1]-nwy[2]!=len||nwx[2]-nwx[3]!=len||nwy[0]-nwy[3]!=len) return;
	if (nwx[0]!=nwx[3]||nwy[0]!=nwy[1]||nwx[2]!=nwx[1]||nwy[2]!=nwy[3]) return;
	len=getdis(nwx[0],nwy[0],x[po[0]],y[po[0]]);
	for (int i=1; i<4; i++) len=max(len,getdis(nwx[i],nwy[i],x[po[i]],y[po[i]]));
	if (len<ans)
	{
		ans=len;
		for (int i=0; i<4; i++) ansx[i]=nwx[p[i]],ansy[i]=nwy[p[i]];
	}
}

void dfs(int nw)
{
	if (nw==4) {check(); return;}
	for (int i=0; i<4; i++) 
		if (!bo[i]) bo[i]=1,p[nw]=i,dfs(nw+1),bo[i]=0;
}

bool check(int l1,int r1,int l2,int r2)
{
	if (l1>r1||l2>r2) return 0;
	return max(l1,l2)<=min(r1,r2);
}

void checkx()
{
	for (int i=0; i<4; i++) po[p[i]]=i;
	for (int i=0; i<4; i++)	nwx[i]=x[po[i]],nwy[i]=y[po[i]];
	if (nwx[0]!=nwx[3]) return;
	if (nwx[1]!=nwx[2]) return;
	if (nwx[1]<=nwx[0]) return;
	len=nwx[1]-nwx[0];
	int l=0,r=300000000,mid,Ans=inf;
	while (l<=r)
	{
		mid=(l+r)>>1;
		if (check(max(nwy[0]-mid-len,nwy[3]-mid),min(nwy[0]+mid-len,nwy[3]+mid),max(nwy[1]-mid-len,nwy[2]-mid),min(nwy[1]+mid-len,nwy[2]+mid)))
			Ans=mid,r=mid-1; else l=mid+1;
	}
	if (Ans<ans)
	{
		ans=Ans; int po=max(max(nwy[0]-Ans-len,nwy[3]-Ans),max(nwy[1]-Ans-len,nwy[2]-Ans));
		nwy[3]=nwy[2]=po,nwy[0]=nwy[1]=po+len;
		for (int i=0; i<4; i++) ansx[i]=nwx[p[i]],ansy[i]=nwy[p[i]];
	}
}

void dfsx(int nw)
{
	if (nw==4) {checkx(); return;}
	for (int i=0; i<4; i++) 
		if (!bo[i]) bo[i]=1,p[nw]=i,dfsx(nw+1),bo[i]=0;
}

void checky()
{
	for (int i=0; i<4; i++) po[p[i]]=i;
	for (int i=0; i<4; i++) nwx[i]=y[po[i]],nwy[i]=x[po[i]];
	if (nwx[0]!=nwx[3]) return;
	if (nwx[1]!=nwx[2]) return;
	if (nwx[1]<=nwx[0]) return;
	len=nwx[1]-nwx[0];
	int l=0,r=300000000,mid,Ans=inf;
	while (l<=r)
	{
		mid=(l+r)>>1;
		if (check(max(nwy[0]-mid-len,nwy[3]-mid),min(nwy[0]+mid-len,nwy[3]+mid),max(nwy[1]-mid-len,nwy[2]-mid),min(nwy[1]+mid-len,nwy[2]+mid)))
			Ans=mid,r=mid-1; else l=mid+1;
	}
	if (Ans<ans)
	{
		ans=Ans; int po=max(max(nwy[0]-Ans-len,nwy[3]-Ans),max(nwy[1]-Ans-len,nwy[2]-Ans));
		nwy[3]=nwy[2]=po,nwy[0]=nwy[1]=po+len;
		for (int i=0; i<4; i++) ansx[i]=nwy[p[i]],ansy[i]=nwx[p[i]];
	}
}

void dfsy(int nw)
{
	if (nw==4) {checky(); return;}
	for (int i=0; i<4; i++) 
		if (!bo[i]) bo[i]=1,p[nw]=i,dfsy(nw+1),bo[i]=0;
}

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		ans=inf;
		for (int i=0; i<4; i++) scanf("%d%d",&x[i],&y[i]);
		memset(bo,0,sizeof(bo)),dfsx(0),dfsy(0);
		for (int i=1; i<15; i++)
		{
			for (int j=0; j<4; j++) dir[j]=(i>>j&1);
			memset(bo,0,sizeof(bo)),dfs(0);
		}
		if (ans==inf) puts("-1"); else
		{
			printf("%d\n",ans);
			for (int i=0; i<4; i++) printf("%d %d\n",ansx[i],ansy[i]);
		}
	}
	return 0;
}