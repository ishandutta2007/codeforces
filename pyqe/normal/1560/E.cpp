#include <bits/stdc++.h>

using namespace std;

long long n,nn,a[500069],fq[26],fq2[26],od[500069],zs;
bitset<26> vtd;
multiset<long long> ms;
vector<long long> vl[26];

int main()
{
	long long t,rr,i,j,p;
	multiset<long long>::iterator it;
	string s;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		cin>>s;
		n=s.length();
		for(i=1;i<=n;i++)
		{
			a[i]=s[i-1]-'a';
		}
		for(i=0;i<26;i++)
		{
			fq[i]=0;
			fq2[i]=0;
			vl[i].clear();
		}
		nn=0;
		for(i=n;i;i--)
		{
			if(!fq[a[i]])
			{
				nn++;
				od[nn]=a[i];
			}
			fq[a[i]]++;
		}
		zs=0;
		for(i=1;i<=nn;i++)
		{
			if(fq[od[i]]%(nn+1-i))
			{
				break;
			}
			fq[od[i]]/=nn+1-i;
			zs+=fq[od[i]];
		}
		if(i<=nn)
		{
			printf("-1\n");
			continue;
		}
		for(i=1;i<=zs;i++)
		{
			fq2[a[i]]++;
		}
		for(i=0;i<26;i++)
		{
			if(fq2[i]!=fq[i])
			{
				break;
			}
		}
		if(i<26)
		{
			printf("-1\n");
			continue;
		}
		ms.clear();
		for(i=1;i<=zs;i++)
		{
			ms.insert(i);
			vl[a[i]].push_back(i);
		}
		for(p=0,i=nn;i;i--)
		{
			for(it=ms.begin();it!=ms.end();it++)
			{
				p++;
				if(a[p]!=a[*it])
				{
					break;
				}
			}
			if(it!=ms.end())
			{
				break;
			}
			for(j=0;j<fq[od[i]];j++)
			{
				ms.erase(vl[od[i]][j]);
			}
		}
		if(!i)
		{
			for(i=1;i<=zs;i++)
			{
				printf("%c",(char)(a[i]+'a'));
			}
			printf(" ");
			for(i=nn;i;i--)
			{
				printf("%c",(char)(od[i]+'a'));
			}
			printf("\n");
		}
		else
		{
			printf("-1\n");
		}
	}
}