#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int t,x,y,n;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&n,&x,&y);
		x+=y;
		if(n==1) printf("1 1\n");
		else if(x==2*n) printf("%d %d\n",n,n);
		else if(x==n+1) printf("%d %d\n",2,n);
		else if(x<n+1) printf("%d %d\n",1,x-1);
		else printf("%d %d\n",x-n+1,n);
	} 
	return 0;
}