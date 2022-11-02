#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define x0 fuckcjb
#define x1 fuckshb
#define y0 fucksf
#define y1 fuckjtjl
int tt=19260817;
int n,m;
int main()
{
	scanf("%d%d",&n,&m);
	printf("%d %d\n",tt,tt);
	for(int i=1;i<n-1;i++)printf("%d %d 1\n",i,i+1);
	printf("%d %d %d\n",n-1,n,tt-n+2);
	m-=n-1;
	for(int i=1;m&&i<=n-2;i++)
	for(int j=i+2;m&&j<=n;j++)
	printf("%d %d 1000000000\n",i,j),m--;
	return 0;
}