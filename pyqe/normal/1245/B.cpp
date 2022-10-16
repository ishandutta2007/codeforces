#include <bits/stdc++.h>

using namespace std;

long long n,fq[2][3],a[169],z[169];
string ky="RPS";
map<char,long long> yk;

int main()
{
	long long t,rr,i,ii,j,c=0;
	string s;
	
	yk['R']=0;
	yk['P']=1;
	yk['S']=2;
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=0;i<3;i++)
		{
			scanf("%lld",&fq[0][i]);
			fq[1][i]=0;
		}
		cin>>s;
		for(i=0;i<n;i++)
		{
			a[i]=yk[s[i]];
			fq[1][a[i]]++;
		}
		c=0;
		for(i=0;i<3;i++)
		{
			c+=min(fq[0][i],fq[1][(i+2)%3]);
		}
		if(c>=(n-1)/2+1)
		{
			printf("YES\n");
			for(i=0;i<n;i++)
			{
				if(fq[0][(a[i]+1)%3])
				{
					z[i]=(a[i]+1)%3;
					fq[0][(a[i]+1)%3]--;
				}
				else
				{
					z[i]=-1;
				}
			}
			j=0;
			for(i=0;i<n;i++)
			{
				for(;j<3&&!fq[0][j];j++);
				if(z[i]==-1)
				{
					z[i]=j;
					fq[0][j]--;
				}
			}
			for(i=0;i<n;i++)
			{
				printf("%c",ky[z[i]]);
			}
			printf("\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}