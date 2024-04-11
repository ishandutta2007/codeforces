#include <bits/stdc++.h>

using namespace std;

long long n,fq[4],sq[4];
bitset<5069> a[2];
vector<long long> pst[4];

int main()
{
	long long i,j,r,ii,k,c=0;
	string s;
	
	scanf("%lld",&n);
	for(ii=0;ii<2;ii++)
	{
		cin>>s;
		for(i=1;i<=n;i++)
		{
			a[ii][i]=s[i-1]-'0';
		}
	}
	for(i=1;i<=n;i++)
	{
		k=a[0][i]*2+a[1][i];
		pst[k].push_back(i);
		fq[k]++;
	}
	for(i=0;i<=n/2;i++)
	{
		k=fq[1]+fq[3]-i;
		for(j=0;j<=n/2;j++)
		{
			sq[3]=j;
			sq[2]=i-j;
			sq[1]=k-j;
			sq[0]=n/2-sq[3]-sq[2]-sq[1];
			for(ii=0;ii<4;ii++)
			{
				if(sq[ii]<0||sq[ii]>fq[ii])
				{
					ii=-1;
					break;
				}
			}
			if(ii!=-1)
			{
				for(ii=0;ii<4;ii++)
				{
					for(r=0;r<sq[ii];r++)
					{
						c++;
						printf("%lld%c",pst[ii][r]," \n"[c==n/2]);
					}
				}
				return 0;
			}
		}
	}
	printf("-1\n");
}