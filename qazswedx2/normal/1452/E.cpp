#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,k,a[2005][2],f[2005];
void getinc(int l,int r)
{
//	printf("inc:l=%d,r=%d\n",l,r);
	if(l<=0&&r<=0)
	{
		f[1]+=r-l+1;
		f[2]-=r-l+1;
		return;
	}
	if(l<=0)
	{
		f[1]+=1-l;
		f[2]-=1-l;
		l=1;
	}
	f[l]++,f[r+1]--;
}
void getdec(int l,int r)
{
//	printf("dec:l=%d,r=%d\n",l,r);
	if(r>n) r=n;
	f[l+1]--,f[r+2]++;
}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
		scanf("%d%d",&a[i][0],&a[i][1]);
	int ans=0;
	for(int i=1;i<=n-k+1;i++)
	{
		int l=i,r=i+k-1,nans=0,nw=0;
		for(int j=1;j<=n;j++)
			f[j]=0;
	//	printf("i=%d\n",i);
		for(int j=1;j<=m;j++)
		{
			int ql=a[j][0],qr=a[j][1],q,ll,rr,v;
			q=max(0,min(r,qr)-max(l,ql)+1);
			nans+=q;
			if(qr-ql+1>=k) ll=ql,rr=qr-k+1,v=k;
			else ll=qr-k+1,rr=ql,v=qr-ql+1;
		//	printf("i=%d,j=%d,q=%d,%d,%d,ll=%d,rr=%d,v=%d\n",i,j,ql,qr,q,ll,rr,v);
			getinc(ll-(v-q)+1,ll);
			getdec(rr,rr+(v-q)-1);
		}
		for(int j=1;j<=n;j++)
			f[j]+=f[j-1];
		for(int j=1;j<=n;j++)
			f[j]+=f[j-1];
		for(int j=1;j<=n;j++)
			nw=max(nw,f[j]);
		ans=max(ans,nans+nw);
	}
	printf("%d\n",ans);
	return 0;
}