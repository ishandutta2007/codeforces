#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
int t,n,k,p[100005],prime[100005],phi[100005],pn=1e5,pt;
ll f[100005],g[22][100005];
vector<int> val[100005];
int l,r;
ll ans;
inline void modifyl(int x,int fl)
{
//	if(!x) printf("modifyl:ans=%lld,f=%lld\n",ans,f[r/x]*fl);
	ans+=f[r/x]*fl;
}
inline void modifyr(int x,int fl)
{
	int sz=val[x].size();
	for(int i=sz-1;i>=0;i--)
	{
		int v=val[x][i];
		if(v<l) break;
	//	printf("modifyr:ans=%lld,f=%lld\n",ans,(f[v]-f[v-1])*fl);
		ans+=(f[x/v]-f[x/v-1])*fl;
	}
}
ll modify(int ql,int qr)
{
	while(r<qr) modifyr(++r,1);
	while(l>ql) modifyl(--l,1);
	while(r>qr) modifyr(r--,-1);
	while(l<ql) modifyl(l++,-1);
//	printf("ql=%d,qr=%d,ans=%lld\n",ql,qr,ans); 
	return (ans+(r-l+1))/2;
}
void solve(ll *a,ll *b,int L,int R,int ql,int qr)
{
	if(L>R) return;
	int mid=(L+R)/2,mid2=-1;
	ll nans=1e18;
	modify(ql,mid);
	for(int i=ql;i<=min(qr,mid);i++)
	{
		ll nw=(ans+(r-l+1))/2+b[i-1];
		if(nw<nans)
		{
			nans=nw;
			mid2=i;
		}
		modifyl(l++,-1);
	}
//	printf("solve:L=%d,R=%d,ql=%d,qr=%d,mid=%d,mid2=%d,nans=%lld\n",L,R,ql,qr,mid,mid2,nans);
	a[mid]=nans;
	solve(a,b,L,mid-1,ql,mid2);
	solve(a,b,mid+1,R,mid2,qr);
}
int main()
{
	phi[1]=1;
	for(int i=2;i<=pn;i++)
	{
		if(!p[i]) prime[++pt]=i,phi[i]=i-1;
		for(int j=1;j<=pt&&i*prime[j]<=pn;j++)
		{
			p[i*prime[j]]=1;
			if(i%prime[j]==0)
			{
				phi[i*prime[j]]=phi[i]*prime[j];
				break;
			}
			phi[i*prime[j]]=phi[i]*(prime[j]-1);
		}
	}
	f[1]=1;
	for(int i=2;i<=pn;i++)
		f[i]=phi[i]*2+f[i-1];
//	for(int i=1;i<=100;i++)
//		printf("%d ",f[i]);
	for(int i=1;i<=pn;i++)
		for(int j=i;j<=pn;j+=i)
			val[j].push_back(i);
	memset(g,0x3f,sizeof(g));
	l=1,r=0,ans=0;
	g[0][0]=0;
	for(int i=1;i<=18;i++)
	{
		solve(g[i],g[i-1],i,pn,1,pn);
	/*	printf("i=%d\n",i);
		for(int j=1;j<=20;j++)
			if(g[i][j]<1e18)
				printf("%lld ",g[i][j]);
			else printf("- ");
		printf("\n");*/
//		return 0;
	}
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		if(k>=20||n<=(1<<k)-1)
			printf("%d\n",n);
		else printf("%lld\n",g[k][n]);
	}
	return 0;
}