#include <bits/stdc++.h>

using namespace std;

long long n,a[2][200069],fq[2][26],pst[2][26];

int main()
{
	long long t,rr,i,ii,c[2],p,k,l;
	string s;
	bool bad;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(ii=0;ii<2;ii++)
		{
			for(i=0;i<26;i++)
			{
				fq[ii][i]=0;
			}
			cin>>s;
			for(i=0;i<n;i++)
			{
				a[ii][i]=s[i]-'a';
				fq[ii][a[ii][i]]++;
				pst[ii][a[ii][i]]=i;
			}
		}
		bad=0;
		for(i=0;i<26;i++)
		{
			if(fq[0][i]!=fq[1][i])
			{
				bad=1;
				break;
			}
		}
		if(bad)
		{
			printf("NO\n");
			continue;
		}
		bad=1;
		for(i=0;i<26;i++)
		{
			if(fq[0][i]>1)
			{
				bad=0;
				break;
			}
		}
		if(!bad)
		{
			printf("YES\n");
			continue;
		}
		for(ii=0;ii<2;ii++)
		{
			c[ii]=0;
			p=0;
			for(i=0;i<26;i++)
			{
				if(fq[ii][i])
				{
					for(;pst[ii][i]>p;c[ii]++)
					{
						k=pst[ii][i];
						l=pst[ii][a[ii][pst[ii][i]-1]];
						swap(a[ii][k],a[ii][l]);
						swap(pst[ii][a[ii][k]],pst[ii][a[ii][l]]);
					}
					p++;
				}
			}
		}
		if(c[0]%2==c[1]%2)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}