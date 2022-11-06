#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,m,cnt,ans;
char buf[233333];
int main()
{
	scanf("%d%d %s",&n,&m,buf+1);
	for(int i=1;i<n;)
	{
		int flag=0;
		for(int j=i+m;j>=i+1;j--)
		{
			if(buf[j]=='1')
			{
				flag=1;
				i=j;
				ans++;
				break;
			}
		}
		if(flag==0)
		{
			printf("-1\n");
			return 0;
		}
	}
	printf("%d\n",ans);
	return 0;
}