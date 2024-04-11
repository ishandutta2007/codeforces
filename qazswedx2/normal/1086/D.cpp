#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int sum[1000005][3],vis[1000005],cnt[15],a[1000005];
void pushup(int x)
{
	sum[x][0]=sum[x*2][0]+sum[x*2+1][0];
	sum[x][1]=sum[x*2][1]+sum[x*2+1][1];
	sum[x][2]=sum[x*2][2]+sum[x*2+1][2];
	vis[x]=vis[x*2]|vis[x*2+1];
}
void modify(int x,int l,int r,int qx,int v)
{
	if(l>qx||r<qx) return;
	if(l==r)
	{
//	printf("modify:l=%d,v=%d\n",l,v);
		vis[x]=(1<<v);
		sum[x][0]=sum[x][1]=sum[x][2]=0;
		sum[x][v]=1;
		a[l]=v;
		return;
	}
	int mid=(l+r)/2;
	modify(x*2,l,mid,qx,v);
	modify(x*2+1,mid+1,r,qx,v);
	pushup(x);
}
int queryl(int x,int l,int r,int &nw,int k)
{
	if(l==r) return l;
	int mid=(l+r)/2;
	if(cnt[(nw|vis[x*2])]>=k) return queryl(x*2,l,mid,nw,k);
	nw|=vis[x*2];
	return queryl(x*2+1,mid+1,r,nw,k);
}
int queryr(int x,int l,int r,int &nw,int k)
{
	if(l==r) return l;
	int mid=(l+r)/2;
	if(cnt[(nw|vis[x*2+1])]>=k) return queryr(x*2+1,mid+1,r,nw,k);
	nw|=vis[x*2+1];
	return queryr(x*2,l,mid,nw,k);
}
/*int queryL(int x,int l,int r,int nw)
{
	if(l==r) return l;
	int mid=(l+r)/2;
	if(cnt[vis[x*2]]>1) return queryL(x*2,l,mid);
	
}*/
int query(int x,int l,int r,int ql,int qr,int fl)
{
//	if(x==1) printf("query:x=%d,l=%d,r=%d,ql=%d,qr=%d,fl=%d\n",x,l,r,ql,qr,fl);
	if(l>qr||r<ql) return 0;
	if(ql<=l&&r<=qr) return sum[x][fl];
	int mid=(l+r)/2;
	return query(x*2,l,mid,ql,qr,fl)+query(x*2+1,mid+1,r,ql,qr,fl); 
}
int n,m;
char s[1000005];
int solve()
{
	int q=vis[1];
	if(cnt[q]==1) return n;
	if(cnt[q]==2)
	{
		int nw=0;
		if(q==3) nw=1;
		if(q==6) nw=2;
		if(q==5) nw=0;
		return sum[1][nw];
	}
	int x=0,ans;
	int l=queryl(1,1,n,x,3),r;
	x=0;
	r=queryr(1,1,n,x,3);
	ans=max(0,r-l+1);
	ans+=query(1,1,n,1,min(l-1,r),(a[l]+2)%3);
	ans+=query(1,1,n,max(r+1,l),n,(a[r]+2)%3);
	x=0;
	int ll=queryl(1,1,n,x,2),rr;
	x=0;
	rr=queryr(1,1,n,x,2);
	if(a[ll]==(a[l]+2)%3) ans+=ll-1;
	if(a[rr]==(a[r]+2)%3) ans+=n-rr;
//	for(int i=1;i<=n;i++)
//		printf("%d ",a[i]);
//	printf("\n");
//	printf("l=%d,r=%d,ll=%d,rr=%d,a=%d,%d,,%d,%d\n",l,r,ll,rr,a[l],a[r],a[ll],a[rr]);
	return ans;
}
int main()
{
	for(int i=1;i<10;i++)
		cnt[i]=cnt[i/2]+i%2;
	scanf("%d%d%s",&n,&m,s+1);
	for(int i=1;i<=n;i++)
	{
		int c=0;
		if(s[i]=='R') c=0;
		if(s[i]=='P') c=1;
		if(s[i]=='S') c=2;
		modify(1,1,n,i,c);
		a[i]=c;
	}
	printf("%d\n",solve());
	for(int i=1;i<=m;i++)
	{
		int x,c=0;
		char ch;
		scanf("%d %c",&x,&ch);
		if(ch=='R') c=0;
		if(ch=='P') c=1;
		if(ch=='S') c=2;
		modify(1,1,n,x,c);
		printf("%d\n",solve());
	}
	return 0;
}