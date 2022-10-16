#include <bits/stdc++.h>

using namespace std;

long long n,a[2][2],pr[3],ky[3];
bitset<3> vtd,spc;

int main()
{
	long long i,j,ii,p=-1,c;
	string s;
	
	scanf("%lld",&n);
	for(ii=0;ii<2;ii++)
	{
		cin>>s;
		for(i=0;i<2;i++)
		{
			a[ii][i]=s[i]-'a';
		}
	}
	printf("YES\n");
	if(a[0][0]!=a[0][1]&&a[1][0]!=a[1][1])
	{
		for(p=1;p>=0&&a[0][p]!=a[1][p];p--);
	}
	if(p!=-1)
	{
		for(i=!p*2;i!=-1+p*4;i+=p*2-1)
		{
			for(j=0;j<n;j++)
			{
				printf("%c",(char)(a[0][p]+i)%3+'a');
			}
		}
		printf("\n");
	}
	else if(a[0][0]!=a[0][1]&&a[0][0]==a[1][1]&&a[0][1]==a[1][0])
	{
		for(p=0;p==a[0][0]||p==a[0][1];p++);
		for(i=0;i<n;i++)
		{
			printf("%c%c%c",(char)a[0][i%2]+'a',(char)p+'a',(char)a[0][1-i%2]+'a');
		}
		printf("\n");
	}
	else
	{
		for(i=0;i<3;i++)
		{
			pr[i]=-1;
		}
		for(ii=0;ii<2;ii++)
		{
			if(a[ii][0]!=a[ii][1])
			{
				pr[a[ii][1]]=a[ii][0];
				spc[a[ii][0]]=1;
			}
		}
		for(p=0;spc[p];p++);
		for(c=0;p<3&&!vtd[p];c++)
		{
			ky[c]=p;
			vtd[p]=1;
			if(pr[p]!=-1)
			{
				p=pr[p];
			}
			else
			{
				for(p=0;p<3&&(vtd[p]||spc[p]);p++);
			}
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<3;j++)
			{
				printf("%c",(char)ky[j]+'a');
			}
		}
		printf("\n");
	}
}