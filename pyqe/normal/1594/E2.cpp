#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

const long long mm=6,dv=1e9+7;
const string ky[mm]={"white","green","red","yellow","blue","orange"};
long long n,m,nn=0,sk[100069],dp[100069][mm],m0[mm][mm],m1[mm][mm],mz[mm][mm],tmp[mm][mm],pwk;
pair<long long,long long> a[100069];
map<long long,bool> vtd;

bool cmp(pair<long long,long long> x,pair<long long,long long> y)
{
	long long ii,k,p[2]={x.fr,y.fr},c[2]={0,0};
	
	for(ii=0;ii<2;ii++)
	{
		for(k=p[ii];k;k/=2,c[ii]++);
	}
	return mp(p[0]>>max(c[0]-c[1],0ll),-c[0])<mp(p[1]>>max(c[1]-c[0],0ll),-c[1]);
}

long long lca(long long x,long long y)
{
	long long ii,k,p[2]={x,y},c[2]={0,0};
	
	for(ii=0;ii<2;ii++)
	{
		for(k=p[ii];k;k/=2,c[ii]++);
	}
	for(ii=0;ii<2;ii++)
	{
		p[ii]>>=max(c[ii]-c[!ii],0ll);
	}
	for(;p[0]!=p[1];p[0]>>=1,p[1]>>=1);
	return p[0];
}

long long pw(long long x,long long y)
{
	if(!y)
	{
		return 1;
	}
	pwk=pw(x,y/2);
	pwk=pwk*pwk%dv;
	if(y%2)
	{
		pwk=pwk*x%dv;
	}
	return pwk;
}

void cop(long long x[mm][mm],long long y[mm][mm])
{
	long long i,j;
	
	for(i=0;i<mm;i++)
	{
		for(j=0;j<mm;j++)
		{
			y[i][j]=x[i][j];
		}
	}
}

void mul(long long x[mm][mm],long long y[mm][mm],long long z[mm][mm])
{
	long long i,j,r;
	
	for(i=0;i<mm;i++)
	{
		for(j=0;j<mm;j++)
		{
			tmp[i][j]=0;
			for(r=0;r<mm;r++)
			{
				tmp[i][j]=(tmp[i][j]+x[i][r]*y[r][j])%dv;
			}
		}
	}
	cop(tmp,z);
}

void mpw(long long x)
{
	if(!x)
	{
		cop(m0,mz);
		return;
	}
	mpw(x/2);
	mul(mz,mz,mz);
	if(x%2)
	{
		mul(mz,m1,mz);
	}
}

int main()
{
	long long i,j,r,k,w,sz,k2,c[2],sm,c2,z=0;
	string s;
	
	for(i=0;i<mm;i++)
	{
		m0[i][i]=1;
		for(j=0;j<=mm;j++)
		{
			m1[i][j]=i%3!=j%3;
		}
	}
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=m;i++)
	{
		scanf("%lld",&k);
		cin>>s;
		for(j=0;ky[j]!=s;j++);
		a[i]={k,j};
		vtd[k]=1;
	}
	sort(a+1,a+m+1,cmp);
	sz=m;
	for(i=1;i<sz;i++)
	{
		k=lca(a[i].fr,a[i+1].fr);
		if(!vtd[k])
		{
			m++;
			a[m]={k,-1};
			vtd[k]=1;
		}
	}
	sort(a+1,a+m+1,cmp);
	c2=m;
	for(i=1;i<=m;i++)
	{
		k=a[i].fr;
		w=a[i].sc;
		for(j=0;j<mm;j++)
		{
			dp[i][j]=j==w||w==-1;
		}
		for(c[0]=0,k2=k;k2;k2/=2,c[0]++);
		for(;nn&&lca(a[sk[nn]].fr,k)==k;nn--)
		{
			for(c[1]=0,k2=a[sk[nn]].fr;k2;k2/=2,c[1]++);
			c2+=c[1]-c[0]-1;
			mpw(c[1]-c[0]);
			for(j=0;j<mm;j++)
			{
				sm=0;
				for(r=0;r<mm;r++)
				{
					sm=(sm+dp[sk[nn]][r]*mz[r][j])%dv;
				}
				dp[i][j]=dp[i][j]*sm%dv;
			}
		}
		nn++;
		sk[nn]=i;
	}
	for(i=0;i<mm;i++)
	{
		z=(z+dp[m][i])%dv;
	}
	z=z*pw(4,(1ll<<n)-1-c2)%dv;
	printf("%lld\n",z);
}