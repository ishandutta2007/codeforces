#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=2e3+1e2+7;

int n,s[N],m;

char a[N][N];

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%s",a[i]+1);
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			s[i]+=a[j][i]-'0';
	for(int i=1;i<=n;i++)
	{
		bool flag=true;
		for(int j=1;j<=m;j++)
			if(a[i][j]=='1'&&s[j]<2)
				flag=false;
		if(flag)
		{
			puts("YES");
			return 0;
		}
	}
	puts("NO");
}