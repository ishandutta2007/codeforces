#include<bits/stdc++.h>
using namespace std;
const int N=105;
const int id[10][10]={{100,99,98,97,96,95,94,93,92,91},
					  {81,82,83,84,85,86,87,88,89,90},
					  {80,79,78,77,76,75,74,73,72,71},
					  {61,62,63,64,65,66,67,68,69,70},
					  {60,59,58,57,56,55,54,53,52,51},
					  {41,42,43,44,45,46,47,48,49,50},
					  {40,39,38,37,36,35,34,33,32,31},
					  {21,22,23,24,25,26,27,28,29,30},
					  {20,19,18,17,16,15,14,13,12,11},
					  {1,2,3,4,5,6,7,8,9,10}};

int read()
{
	int s=0;
	char c=getchar(),lc='+';
	while (c<'0'||'9'<c) lc=c,c=getchar();
	while ('0'<=c&&c<='9') s=s*10+c-'0',c=getchar();
	return lc=='-'?-s:s;
}
void write(int x)
{
	if (x<0) putchar('-'),x=-x;
	if (x<10) putchar(x+'0');
	else write(x/10),putchar(x%10+'0');
}
void print(int x=-1,char c='\n')
{
	write(x);
	putchar(c);
}
long double f[N],g[N];
int to[N];

signed main(signed Recall,char *_902_[])
{
	(void)Recall,(void)_902_;
	for (int i=0;i<10;i++)
	for (int j=0;j<10;j++)
	{
		int x=read();
		if (x) to[id[i][j]]=id[i-x][j];
	}
	for (int i=1;i<=100;i++) g[i]=114514;
	for (int i=99;i>=91;i--)
	{
		int x=0;
		for (int j=1;j<=6;j++)
		if (i+j<=100) f[i]+=f[i+j]+1;
				 else x++;
		f[i]+=x;
		f[i]/=6-x;
	}
	for (int i=90;i>=1;i--)
	{
		for (int j=1;j<=6;j++) f[i]+=(min(f[i+j],g[i+j])+1)/6;
		if (to[i]) g[i]=f[to[i]];
	}
	printf("%.10lf",(double)min(f[1],g[1]));
	
	return 0;
}