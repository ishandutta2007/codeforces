#include <bits/stdc++.h>

using namespace std;

long long n,pr[26],dsu[26];
bitset<26> vtd,spc;

long long fd(long long x)
{
	if(dsu[x]!=x)
	{
		dsu[x]=fd(dsu[x]);
	}
	return dsu[x];
}

int main()
{
	long long i,j,k,l,sz,p;
	string s;
	
	for(i=0;i<26;i++)
	{
		pr[i]=-1;
		dsu[i]=i;
	}
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		cin>>s;
		sz=s.length();
		for(j=0;j<sz-1;j++)
		{
			k=s[j]-'a';
			l=s[j+1]-'a';
			if(pr[k]==-1)
			{
				if(fd(k)==fd(l)||vtd[l])
				{
					printf("NO\n");
					return 0;
				}
				pr[k]=l;
				dsu[fd(k)]=fd(l);
				vtd[l]=1;
			}
			else if(pr[k]!=l)
			{
				printf("NO\n");
				return 0;
			}
		}
		for(j=0;j<sz;j++)
		{
			spc[s[j]-'a']=1;
		}
	}
	for(i=0;i<26;i++)
	{
		if(!vtd[i]&&spc[i])
		{
			for(p=i;p+1;p=pr[p])
			{
				printf("%c",(char)p+'a');
			}
		}
	}
	printf("\n");
}