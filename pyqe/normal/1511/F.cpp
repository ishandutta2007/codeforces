#include <bits/stdc++.h>

using namespace std;

const long long mm=120,dv=998244353;
long long n,m,nn[69],nm=0,a[69][69],pst[69][69],m0[mm][mm],m1[mm][mm],mz[mm][mm],tmp[mm][mm],a0[mm],pwk;

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
	
	for(i=0;i<nm;i++)
	{
		for(j=0;j<nm;j++)
		{
			y[i][j]=x[i][j];
		}
	}
}

void mul(long long x[mm][mm],long long y[mm][mm],long long z[mm][mm])
{
	long long i,j,r;
	
	for(i=0;i<nm;i++)
	{
		for(j=0;j<nm;j++)
		{
			tmp[i][j]=0;
			for(r=0;r<nm;r++)
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
	long long i,j,r,p,z=0;
	string s;
	
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++)
	{
		cin>>s;
		nn[i]=s.length();
		for(j=1;j<=nn[i];j++)
		{
			a[i][j]=s[j-1]-'a';
		}
		for(j=0;j<nn[i];j++)
		{
			for(r=0;r<nn[i]-j-1;r++)
			{
				m1[nm+1][nm]=1;
				nm++;
			}
			pst[i][j]=nm;
			nm++;
		}
	}
	for(i=0;i<nm;i++)
	{
		m0[i][i]=1;
	}
	for(i=1;i<=n;i++)
	{
		for(j=0;j<nn[i];j++)
		{
			for(r=1;r<=n;r++)
			{
				for(p=1;p<=min(nn[r],nn[i]-j);p++)
				{
					if(a[i][j+p]!=a[r][p])
					{
						p=-1;
						break;
					}
				}
				if(p!=-1)
				{
					if(j+nn[r]<nn[i])
					{
						m1[pst[i][j]-nn[r]+1][pst[i][j+nn[r]]]++;
					}
					else if(j+nn[r]==nn[i])
					{
						for(p=1;p<=n;p++)
						{
							m1[pst[i][j]-nn[r]+1][pst[p][0]]++;
						}
					}
					else if(j+nn[r]>nn[i])
					{
						m1[pst[i][j]-(nn[i]-j)+1][pst[r][nn[i]-j]]++;
					}
				}
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		a0[pst[i][0]]=1;
	}
	mpw(m);
	for(i=0;i<nm;i++)
	{
		for(j=1;j<=n;j++)
		{
			z=(z+a0[i]*mz[i][pst[j][0]])%dv;
		}
	}
	z=z*pw(n,dv-2)%dv;
	printf("%lld\n",z);
}