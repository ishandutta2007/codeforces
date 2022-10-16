#include <bits/stdc++.h>

using namespace std;

const long long d=26;
long long n,m,a[100069];
vector<long long> vl[d][2];

int main()
{
	long long t,rr,i,ii,k,e,p,sz;
	string s;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		cin>>s;
		n=s.length();
		for(i=0;i<d;i++)
		{
			for(ii=0;ii<2;ii++)
			{
				vl[i][ii].clear();
			}
		}
		for(i=1;i<=n;i++)
		{
			k=s[i-1]-'a';
			vl[k][i%2].push_back(i);
		}
		cin>>s;
		m=s.length();
		for(i=1;i<=m;i++)
		{
			a[i]=s[i-1]-'a';
		}
		for(ii=0;ii<2;ii++)
		{
			k=-ii;
			for(i=1;i<=m;i++)
			{
				e=(k+1)%2;
				p=upper_bound(vl[a[i]][e].begin(),vl[a[i]][e].end(),k)-vl[a[i]][e].begin();
				sz=vl[a[i]][e].size();
				if(p>=sz)
				{
					break;
				}
				k=vl[a[i]][e][p];
			}
			if(i>m&&k%2==n%2)
			{
				break;
			}
		}
		if(ii<2)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}