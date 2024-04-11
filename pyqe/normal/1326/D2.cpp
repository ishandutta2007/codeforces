#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,nn,aa[1000069],a[1000069],faf[1000069];

int main()
{
	long long t,rr,i,j,ii,p,c,lb,rb;
	pair<long long,pair<long long,long long>> mxe;
	string s;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		cin>>s;
		n=s.length();
		for(i=1;i<=n;i++)
		{
			aa[i]=s[i-1]-'a';
		}
		for(p=1;p<n+1-p&&aa[p]==aa[n+1-p];p++);
		p--;
		nn=n-p*2;
		mxe={-1e18,{-1,-1}};
		for(ii=0;ii<2;ii++)
		{
			for(i=1;i<=nn;i++)
			{
				a[i]=aa[!ii?p+i:p+nn+1-i];
			}
			faf[0]=-1;
			for(i=1;i<=nn;i++)
			{
				for(j=faf[i-1];j+1&&a[j+1]!=a[i];j=faf[j]);
				faf[i]=j+1;
			}
			c=0;
			for(i=nn;i;i--)
			{
				for(;c+1&&a[c+1]!=a[i];c=faf[c]);
				c++;
			}
			mxe=max(mxe,{c,{p+c*!ii+1,p+c*!ii+nn-c}});
		}
		lb=mxe.sc.fr;
		rb=mxe.sc.sc;
		for(i=1;i<=n;i++)
		{
			if(i<lb||i>rb)
			{
				printf("%c",(char)aa[i]+'a');
			}
		}
		printf("\n");
	}
}