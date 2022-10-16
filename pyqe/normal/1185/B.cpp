#include <bits/stdc++.h>

using namespace std;

long long n[2],a[2][1000069],fq[2][1000069];

int main()
{
	long long t,rr,i,ii,ln,k,l;
	string s;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		for(ii=0;ii<2;ii++)
		{
			cin>>s;
			ln=s.length();
			n[ii]=0;
			l=-1;
			for(i=1;i<=ln;i++)
			{
				k=s[i-1]-'a';
				if(k!=l)
				{
					n[ii]++;
					fq[ii][n[ii]]=0;
				}
				a[ii][n[ii]]=k;
				fq[ii][n[ii]]++;
				l=k;
			}
		}
		if(n[0]!=n[1])
		{
			printf("NO\n");
			continue;
		}
		for(i=1;i<=n[0];i++)
		{
			if(a[0][i]!=a[1][i]||fq[0][i]>fq[1][i])
			{
				i=-1;
				break;
			}
		}
		if(i==-1)
		{
			printf("NO\n");
		}
		else
		{
			printf("YES\n");
		}
	}
}