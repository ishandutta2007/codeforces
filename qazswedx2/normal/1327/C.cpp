#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,t;
char tans[1000005];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<n;i++) tans[++t]='U';
	for(int i=1;i<m;i++) tans[++t]='L';
	for(int i=1;i<=n;i++)
	{
		if(i%2)
		{
			for(int j=1;j<m;j++) tans[++t]='R';
		}
		else
		{
			for(int j=1;j<m;j++) tans[++t]='L';
		}
		if(i<n) tans[++t]='D';
	}
	printf("%d\n",t);
	for(int i=1;i<=t;i++)
		printf("%c",tans[i]);
	return 0;
}