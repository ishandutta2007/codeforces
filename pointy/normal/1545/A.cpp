#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mem(x) memset(x,0,sizeof(x))
//const ll inf=1000000000000000000; 

const int N=100001;
int n,m,T; 
int a[N],b[N];
int c[N][2],d[N][2];

inline int read()
{
	char C=getchar();
	int F=1,ANS=0;
	while (C<'0'||C>'9')
	{
		if (C=='-') F=-1;
		C=getchar();
	}
	while (C>='0'&&C<='9')
	{
		ANS=ANS*10+C-'0';
		C=getchar();
	}
	return F*ANS;
} 

void work()
{
	n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<=n;i++) b[i]=a[i];
	sort(b+1,b+n+1);
	mem(c),mem(d);
	for (int i=1;i<=n;i++) 
	{
		c[a[i]][i%2]++;
		d[b[i]][i%2]++;
	}
	for (int i=1;i<=100000;i++) 
	{
		if (c[i][0]!=d[i][0]||c[i][1]!=d[i][1]) 
		{
			puts("NO");
			return;
		}
	}
	puts("YES");
	return;
}

int main()
{
	T=read();
	while (T--)
	{
		work();
	}
	return 0;
}