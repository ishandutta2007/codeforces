#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int mod=998244353;
inline int addmod(int x)
{
	return x>=mod?x-mod:x;
}
inline int submod(int x)
{
	return x<0?x+mod:x;
}
int fpow(int x,int y)
{
	int ans=1;
	while(y)
	{
		if(y&1) ans=1ll*ans*x%mod;
		x=1ll*x*x%mod;
		y/=2;
	}
	return ans;
}
//int buf[10000005],*p1=buf;
/*struct Vector
{
	int *p,sz;
	Vector(){p=NULL,sz=0;}
	Vector(int x)
	{
		sz=x;
		p=malloc(p);
	}
	void setlen(int x)
	{
		(*this)=Vector(x);
	}
	int& operator[](int x)
	{
		return p[x];
	}
	int operator[](int x) const
	{
		return p[x];
	}
};*/
struct pt
{
	vector<int> v;
	int len;
	pt(){len=0;}
	void setlen(int x)
	{
		len=x;
		v.resize(len);
	}
};
pt operator+(const pt &x,const pt &y)
{
	pt z;
	z.setlen(x.len);
	for(int i=0;i<z.len;i++)
		z.v[i]=addmod(x.v[i]+y.v[i]);
	return z;
}
pt operator*(const pt &x,const pt &y)
{
	pt z;
	z.setlen(x.len);
	for(int i=0;i<z.len;i++)
		z.v[i]=1ll*x.v[i]*y.v[i]%mod;
	return z;
}
pt operator*(const pt &x,const int &y)
{
	pt z;
	z.setlen(x.len);
	for(int i=0;i<z.len;i++)
		z.v[i]=1ll*x.v[i]*y%mod;
	return z;
}
pt operator*(const int &x,const pt &y)
{
	return y*x;
}
int inv2;
pt fwt(pt a)
{
	int lim=a.len;
	for(int k=1;k<lim;k<<=1)
		for(int i=0,r=k*2;i<lim;i+=r)
			for(int j=0;j<k;j++)
			{
				int x=a.v[i+j],y=a.v[i+j+k];
				a.v[i+j]=addmod(x+y);
				a.v[i+j+k]=submod(x-y);
			}
	return a;
}
pt ifwt(pt a)
{
	int lim=a.len;
	for(int k=1;k<lim;k<<=1)
		for(int i=0,r=k*2;i<lim;i+=r)
			for(int j=0;j<k;j++)
			{
				int x=a.v[i+j],y=a.v[i+j+k];
				a.v[i+j]=1ll*inv2*addmod(x+y)%mod;
				a.v[i+j+k]=1ll*inv2*submod(x-y)%mod;
			}
	return a;
}
pt modify(pt x,int fl)
{
	pt y;
	y.setlen(x.len*2);
	for(int i=0;i<x.len;i++)
		y.v[i]=x.v[i];
	if(fl==0)
	{
		for(int i=0;i<x.len;i++)
			y.v[i+x.len]=x.v[i];
	}
	else
	{
		for(int i=0;i<x.len;i++)
			y.v[i+x.len]=addmod(mod-x.v[i]);
	}
	return y;
}
int n,k,m,d[150005],sz[150005],a[150005],fr[100005],infr[100005],pn=1e5;
int tsz[150005];
pt dp[150005][17],tmp2[17],tmp3[17];
int C(int x,int y)
{
	return 1ll*fr[x]*infr[y]%mod*infr[x-y]%mod;
}
void ins(int x)
{
	int u=1;
	sz[u]++;
	for(int i=m-1;i>=0;i--)
	{
		int q=(x>>i)&1;
		u=u*2+q;
		sz[u]++;
	}
}
pt getpt(int u,int x)
{
	pt tmp;
	tmp.setlen(1<<(m-d[u]));
	tmp.v[0]=1;
	for(int i=0;i<m-d[u];i++)
	{
		int fl=(x>>i)&1,lim=(1<<i);
		if(fl==0)
		{
			for(int i=lim;i<2*lim;i++)
				tmp.v[i]=tmp.v[i-lim];
		}
		else
		{
			for(int i=lim;i<2*lim;i++)
				tmp.v[i]=addmod(mod-tmp.v[i-lim]);
		}
	}
/*	printf("getpt:u=%d,x=%d,tmp=",u,x);
	for(int i=0;i<tmp.len;i++)
		printf("%d ",tmp.v[i]);
	printf("\n");*/
	return tmp;
}
void add(int u,int x)
{
//	printf("add:u=%d,x=%d\n",u,x);
	for(int i=0;i<=k;i++)
		tmp2[i]=infr[i]*getpt(u,x-i);
	for(int i=0;i<=k;i++)
	{
		tmp3[i]=dp[u][i];
		dp[u][i]=pt();
		dp[u][i].setlen(1<<(m-d[u]));
	}
	for(int i=0;i<=k;i++)
		for(int j=0;i+j<=k;j++)
		{
		//	printf("i=%d,j=%d,len=%d,%d\n",i,j,tmp2[i].len,tmp3[j].len);
			int *p=&tmp2[i].v[0],*q=&tmp3[j].v[0],*ans=&dp[u][i+j].v[0];
			for(int ll=0;ll<tmp2[i].len;ll++)
				ans[ll]=addmod(ans[ll]+1ll*p[ll]*q[ll]%mod);
		}
}
int main()
{
	//freopen("CF1408I.in","r",stdin);
	//freopen("CF1408I.out","w",stdout);
	inv2=fpow(2,mod-2);
	fr[0]=infr[0]=1;
	for(int i=1;i<=pn;i++)
	{
		fr[i]=1ll*fr[i-1]*i%mod;
		infr[i]=fpow(fr[i],mod-2);
	}
	scanf("%d%d%d",&n,&k,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		ins(a[i]);
	}
	sort(a+1,a+n+1);
	d[1]=0;
	for(int i=2;i<(1<<(m+1));i++)
		d[i]=d[i>>1]+1;
	for(int i=(1<<(m+1))-1;i>=1;i--)
	{
		if(!sz[i]||(1<<(m-d[i]))<=k)
			continue;
		int l,r;
		l=((i-(1<<d[i]))<<(m-d[i])),r=l+(1<<(m-d[i]));
		l+=k;
		l=lower_bound(a+1,a+n+1,l)-a;
		r=lower_bound(a+1,a+n+1,r)-a;
		tsz[i]=r-l;
	//	if(i%10==0) printf("i=%d,tsz=%d,m=%d,d=%d\n",i,tsz[i],m,d[i]);
		if(l==r) continue;
		if((1<<(m-d[i]))<=2*k)
		{
			l=((i-(1<<d[i]))<<(m-d[i])),r=l+(1<<(m-d[i]));
			l+=k;
			for(int j=0;j<=k;j++)
			{
				dp[i][j].setlen((1<<(m-d[i])));
				if(j==0)
				{
					for(int ll=0;ll<dp[i][j].len;ll++)
						dp[i][j].v[ll]=1;
				}
			}
		}
		else
		{
			for(int j=0;j<=k;j++)
				dp[i][j].setlen(1<<(m-d[i]));
			for(int j=0;j<=k;j++)
			{
				dp[i*2][j]=modify(dp[i*2][j],0);
				dp[i*2+1][j]=modify(dp[i*2+1][j],tsz[i*2+1]%2);
			}
			if(dp[i*2][0].len==0)
			{
				int ls=i*2;
				for(int j=0;j<=k;j++)
				{
					dp[ls][j].setlen((1<<(m-d[i])));
					if(j==0)
					{
						for(int ll=0;ll<dp[ls][j].len;ll++)
							dp[ls][j].v[ll]=1;
					}
				}
			}
			if(dp[i*2+1][0].len==0)
			{
				int rs=i*2+1;
				for(int j=0;j<=k;j++)
				{
					dp[rs][j].setlen((1<<(m-d[i])));
					if(j==0)
					{
						for(int ll=0;ll<dp[rs][j].len;ll++)
							dp[rs][j].v[ll]=1;
					}
				}
			}
			for(int j=0;j<=k;j++)
				for(int ll=0;ll+j<=k;ll++)
				{
				/*	if(ll+j==0)
					{
						printf("j=%d,ll=%d\n",j,ll);
						for(int q=0;q<dp[i*2][j].len;q++)
							printf("%d ",dp[i*2][j].v[q]);
						printf("\n");
						for(int q=0;q<dp[i*2][j].len;q++)
							printf("%d ",dp[i*2+1][ll].v[q]);
						printf("\n");
					}*/
					dp[i][ll+j]=dp[i][ll+j]+dp[i*2][j]*dp[i*2+1][ll];
				}
			l=(i*2+1-(1<<d[i*2+1]))<<(m-d[i*2+1]);
			r=l+k;
		}
	//	printf("i=%d,l=%d,r=%d\n",i,l,r);
		l=lower_bound(a+1,a+n+1,l)-a;
		r=lower_bound(a+1,a+n+1,r)-a;
		for(int j=l;j<r;j++)
			add(i,a[j]);
	/*	for(int j=0;j<=k;j++)
		{
			printf("i=%d,j=%d,dp=",i,j);
			for(int ll=0;ll<dp[i][j].len;ll++)
				printf("%d ",dp[i][j].v[ll]);
			printf("\n");
		}*/
	}
	pt p=dp[1][k];
	p=ifwt(p);
	int mul=fpow(n,1ll*k*(mod-2)%(mod-1));
//	printf("mul=%d,p=%d\n",mul,p.len);
	for(int i=0;i<(1<<m);i++)
	{
		p.v[i]=1ll*p.v[i]*mul%mod*fr[k]%mod;
		printf("%d ",p.v[i]);
	}
	return 0;
}