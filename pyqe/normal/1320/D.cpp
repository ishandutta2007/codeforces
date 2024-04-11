#include <bits/stdc++.h>

using namespace std;

long long n,p2[200069][3],ip2[200069][3],ps[200069][3],fq[200069],pr[200069],pwk,inf=1e9,dv[3]={inf+7,inf+9,inf+21};
bitset<200069> a;

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
	long long t,rr,i,j,ii,iv[3],st[2],ln,p,z[2][3],sm[2];
	string s;
	
	scanf("%lld",&n);
	cin>>s;
	for(i=0;i<3;i++)
	{
		p2[0][i]=1;
		ip2[0][i]=1;
		iv[i]=pw(2,dv[i]-2,dv[i]);
	}
	for(i=1;i<=n;i++)
	{
		a[i]=s[i-1]-'0';
		for(j=0;j<3;j++)
		{
			p2[i][j]=p2[i-1][j]*2%dv[j];
			ip2[i][j]=ip2[i-1][j]*iv[j]%dv[j];
			ps[i][j]=(ps[i-1][j]+p2[i][j]*a[i])%dv[j];
		}
		fq[i]=fq[i-1];
		if(i-1&&a[i]&&a[i-1])
		{
			for(j=0;j<3;j++)
			{
				p2[i][j]=p2[i-2][j];
				ip2[i][j]=ip2[i-2][j];
				ps[i][j]=ps[i-2][j];
			}
			fq[i]=fq[i-2]+1;
		}
	}
	for(i=n;i+1;i--)
	{
		pr[i]=pr[i+1];
		if(i==n||!a[i+1])
		{
			pr[i]=i;
		}
	}
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld%lld",st,st+1,&ln);
		for(ii=0;ii<2;ii++)
		{
			st[ii]--;
			p=min(pr[st[ii]],st[ii]+ln);
			for(i=0;i<3;i++)
			{
				z[ii][i]=(ps[st[ii]+ln][i]+dv[i]-ps[p][i])*ip2[p][i]%dv[i];
				if((p-st[ii])%2)
				{
					z[ii][i]=(z[ii][i]*2+2)%dv[i];
				}
			}
			sm[ii]=fq[st[ii]+ln]-fq[p]+(p-st[ii])/2;
		}
		for(i=0;i<3;i++)
		{
			if(z[0][i]!=z[1][i])
			{
				i=-1;
				break;
			}
		}
		if(i!=-1&&sm[0]==sm[1])
		{
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}
	}
}