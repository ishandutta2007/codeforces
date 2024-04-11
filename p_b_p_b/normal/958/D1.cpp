#include<bits/stdc++.h>
using namespace std;
int n;
int to[202020][2];
int sum[200][200];
int read()
{
	int ret=0;
	char ch=getchar();
	while (ch>'9'||ch<'0') ch=getchar();
	while (ch<='9'&&ch>='0') ret=ret*10+ch-48,ch=getchar();
	return ret;
}
int gcd(int x,int y){return y==0?x:gcd(y,x%y);}
int main()
{
	register int i,x,y,z;
	n=read();
	for (i=1;i<=n;i++)
	{
		x=read()+read();
		y=read();
		z=gcd(x,y);
		x/=z;y/=z;
		sum[x][y]++;
		to[i][0]=x;to[i][1]=y;
	}
	for (i=1;i<=n;i++) printf("%d ",sum[to[i][0]][to[i][1]]);
}