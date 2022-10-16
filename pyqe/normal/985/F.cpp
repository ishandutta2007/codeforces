#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,a[200069],pr[26][200069],p2[200069][3],ps[26][200069][3],pwk,dv[3]={(long long)1e9+7,(long long)1e9+9,(long long)1e9+21};
pair<long long,long long> as[26];

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
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long t,rr,i,j,r,ii,k,p[2],ln,tmp[2][26][3];
	string s;
	
	cin>>n>>t>>s;
	for(i=1;i<=n;i++)
	{
		a[i]=s[i-1]-'a';
		for(j=0;j<3;j++)
		{
			if(i-1)
			{
				p2[i][j]=p2[i-1][j]*2%dv[j];
			}
			else
			{
				p2[i][j]=1;
			}
		}
		for(j=0;j<26;j++)
		{
			for(r=0;r<3;r++)
			{
				ps[j][i][r]=ps[j][i-1][r];
			}
		}
		for(j=0;j<3;j++)
		{
			ps[a[i]][i][j]=(ps[a[i]][i][j]+p2[i][j])%dv[j];
		}
	}
	for(i=0;i<26;i++)
	{
		pr[i][n+1]=n+1;
		for(j=n;j;j--)
		{
			pr[i][j]=pr[i][j+1];
			if(a[j]==i)
			{
				pr[i][j]=j;
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=0;j<3;j++)
		{
			p2[i][j]=pw(p2[i][j],dv[j]-2,dv[j]);
		}
	}
	for(rr=0;rr<t;rr++)
	{
		cin>>p[0]>>p[1]>>ln;
		for(ii=0;ii<2;ii++)
		{
			for(i=0;i<26;i++)
			{
				as[i]={pr[i][p[ii]],i};
			}
			sort(as,as+26);
			for(i=0;i<26;i++)
			{
				k=as[i].sc;
				for(j=0;j<3;j++)
				{
					tmp[ii][i][j]=(ps[k][p[ii]+ln-1][j]+dv[j]-ps[k][p[ii]-1][j])*p2[p[ii]][j]%dv[j];
				}
			}
		}
		for(j=0,i=0;j!=-1&&i<26;i++)
		{
			for(j=0;j<3;j++)
			{
				if(tmp[0][i][j]!=tmp[1][i][j])
				{
					j=-1;
					break;
				}
			}
		}
		if(j!=-1)
		{
			cout<<"YES\n";
		}
		else
		{
			cout<<"NO\n";
		}
	}
}