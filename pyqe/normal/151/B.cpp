#include <bits/stdc++.h>

using namespace std;

long long n,a[6],zs[3];
string sq[3][100069],ky[3]={"If you want to call a taxi, you should call: ","If you want to order a pizza, you should call: ","If you want to go to a cafe with a wonderful girl, you should call: "};

int main()
{
	long long i,j,r,sz,k,w,mn,c[3],z[3]={0,0,0};
	string s;
	char ch;
	
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&sz);
		cin>>s;
		for(j=0;j<3;j++)
		{
			c[j]=0;
		}
		for(j=0;j<sz;j++)
		{
			w=10;
			mn=10;
			for(r=0;r<6;r++)
			{
				if(r==2||r==4)
				{
					scanf(" %c",&ch);
				}
				scanf(" %c",&ch);
				k=ch-'0';
				if(w==10||w==k)
				{
					w=k;
				}
				else
				{
					w=-1;
				}
				if(k<mn)
				{
					mn=k;
				}
				else
				{
					mn=-1;
				}
			}
			c[0]+=w!=-1;
			c[1]+=mn!=-1;
			c[2]+=w==-1&&mn==-1;
		}
		for(j=0;j<3;j++)
		{
			if(c[j]>z[j])
			{
				z[j]=c[j];
				zs[j]=0;
			}
			if(c[j]==z[j])
			{
				zs[j]++;
				sq[j][zs[j]]=s;
			}
		}
	}
	for(i=0;i<3;i++)
	{
		printf("%s",ky[i].c_str());
		for(j=1;j<=zs[i];j++)
		{
			printf("%s",sq[i][j].c_str());
			if(j<zs[i])
			{
				printf(", ");
			}
			else
			{
				printf(".\n");
			}
		}
	}
}