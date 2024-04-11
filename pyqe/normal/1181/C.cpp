#include <bits/stdc++.h>

using namespace std;

long long d[1069],b[1069],sz,z=0,w,c,k,l,kk,smb[1069][1069];
bool sm[1069][1069];
string a[1069];
map<pair<long long,long long>,long long> vtd[1069];

int main()
{
	long long n,m,i,j;
	
	scanf("%lld%lld",&n,&m);
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(j=0;j<m;j++)
	{
		sz=0;
		c=0;
		w=0;
		for(i=0;i<n;i++)
		{
			if(j>0&&a[i][j]!=a[i][j-1])
			{
				sm[i][j]=true;
			}
			smb[i+1][j]=smb[i][j]+sm[i][j];
		}
		for(i=0;i<n;i++)
		{
			if(i==n-1||a[i][j]!=a[i+1][j])
			{
				d[sz]=c+1;
				c=0;
				w+=d[sz];
				b[sz]=w;
				sz++;
			}
			else
			{
				c++;
			}
		}
		for(i=1;i<sz-1;i++)
		{
			if(d[i-1]>=d[i]&&d[i]<=d[i+1])
			{
				k=b[i]-d[i]-d[i];
				l=b[i]+d[i]-1;
				kk=vtd[j][make_pair(k,l)];
				if(smb[l+1][j]-smb[k][j]>0)
				{
					//cout<<smb[l+1][j]<<" "<<smb[k][j]<<endl;
					kk=0;
				}
				vtd[j+1][make_pair(k,l)]=kk+1;
				z+=kk+1;
				//cout<<kk+1<<endl;
			}
		}
	}
	printf("%lld\n",z);
}