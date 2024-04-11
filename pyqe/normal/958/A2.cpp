#include <bits/stdc++.h>

using namespace std;

long long n,m,d=26,pc[400069][3],ipc[400069][3],a[2069][2069],pwk,dv[3]={(long long)1e9+7,(long long)1e9+9,(long long)1e9+21};
map<array<long long,3>,long long> pst;

long long pw(long long x,long long y,long long mo)
{
	if(!y)
	{
		return 1;
	}
	pwk=pw(x,y/2,mo);
	pwk=pwk*pwk%mo;
	if(y%2)
	{
		pwk=pwk*x%mo;
	}
	return pwk;
}

int main()
{
	long long i,j,r;
	array<long long,3> sm={0,0,0};
	char ch;
	
	scanf("%lld%lld",&n,&m);
	for(i=0;i<3;i++)
	{
		pc[0][i]=1;
		ipc[0][i]=1;
	}
	for(i=1;i<=n*m;i++)
	{
		for(j=0;j<3;j++)
		{
			pc[i][j]=pc[i-1][j]*d%dv[j];
			ipc[i][j]=pw(pc[i][j],dv[j]-2,dv[j]);
		}
	}
	for(i=0;i<n;i++)
	{
		if(i>=m)
		{
			for(j=0;j<m;j++)
			{
				for(r=0;r<3;r++)
				{
					sm[r]=(sm[r]+dv[r]-a[i-m][j]*pc[j][r]%dv[r])%dv[r];
				}
			}
		}
		for(j=0;j<3;j++)
		{
			sm[j]=sm[j]*ipc[m][j]%dv[j];
		}
		for(j=0;j<m;j++)
		{
			scanf(" %c",&ch);
			a[i][j]=ch-'a';
			for(r=0;r<3;r++)
			{
				sm[r]=(sm[r]+a[i][j]*pc[m*(m-1)+j][r])%dv[r];
			}
		}
		if(i>=m-1)
		{
			pst[sm]=i+1-m+1;
		}
	}
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf(" %c",&ch);
			a[i][j]=ch-'a';
		}
	}
	for(i=0;i<3;i++)
	{
		sm[i]=0;
	}
	for(i=0;i<n;i++)
	{
		if(i>=m)
		{
			for(j=0;j<m;j++)
			{
				for(r=0;r<3;r++)
				{
					sm[r]=(sm[r]+dv[r]-a[j][i-m]*pc[j*m][r]%dv[r])%dv[r];
				}
			}
		}
		for(j=0;j<3;j++)
		{
			sm[j]=sm[j]*ipc[1][j]%dv[j];
		}
		for(j=0;j<m;j++)
		{
			for(r=0;r<3;r++)
			{
				sm[r]=(sm[r]+a[j][i]*pc[j*m+m-1][r])%dv[r];
			}
		}
		if(i>=m-1)
		{
			if(pst[sm])
			{
				printf("%lld %lld\n",pst[sm],i+1-m+1);
				break;
			}
		}
	}
}