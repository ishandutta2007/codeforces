#include <bits/stdc++.h>

using namespace std;

const char ky[4][2]={{'I','V'},{'X','L'},{'C','D'},{'M','V'}};
long long n,m,sq[100069],zs=0;

int main()
{
	long long ln,i,j,k,ml,z=0;
	char ch;
	string s;
	
	scanf("%lld",&n);
	if(scanf("%lld",&m)!=1)
	{
		scanf(" %c",&ch);
		m=-1;
	}
	cin>>s;
	ln=s.length();
	for(i=0;i<ln;i++)
	{
		k=s[i]-'0';
		if(k<0||k>9)
		{
			k=s[i]-'A'+10;
		}
		z=z*n+k;
	}
	if(m!=-1)
	{
		for(;z;z/=m)
		{
			zs++;
			sq[zs]=z%m;
		}
		for(i=zs;i;i--)
		{
			if(sq[i]<=9)
			{
				printf("%lld",sq[i]);
			}
			else
			{
				printf("%c",(char)sq[i]-10+'A');
			}
		}
		if(!zs)
		{
			printf("0");
		}
		printf("\n");
	}
	else
	{
		ml=1000;
		for(i=3;i>=0;i--)
		{
			k=z/ml%10;
			if(!k);
			else if(k<=3)
			{
				for(j=0;j<k;j++)
				{
					printf("%c",ky[i][0]);
				}
			}
			else if(k==4)
			{
				printf("%c%c",ky[i][0],ky[i][1]);
			}
			else if(k<=8)
			{
				printf("%c",ky[i][1]);
				for(j=0;j<k-5;j++)
				{
					printf("%c",ky[i][0]);
				}
			}
			else
			{
				printf("%c%c",ky[i][0],ky[i+1][0]);
			}
			ml/=10;
		}
		printf("\n");
	}
}