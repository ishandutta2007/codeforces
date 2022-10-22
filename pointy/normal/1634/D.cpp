#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mem(x) memset(x,0,sizeof(x))
#define printYes puts("Yes")
#define printYES puts("YES")
#define printNo puts("No")
#define printNO puts("NO")

const ll inf=1000000000000000000; 
//const ll mod=998244353;
//const ll mod=1000000007;

const int N=500005;
int n,m; 
int a[N];

inline int read()
{
    int F=1,ANS=0;
	char C=getchar();
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

int ask(int x,int y,int z)
{
	printf("? %d %d %d\n",x,y,z);
	fflush(stdout);
	int res=read();
	if (res==-1) exit(0);
	return res;
}

void submit(int x,int y)
{
	printf("! %d %d\n",x,y);
	fflush(stdout);
}

void work()
{
	n=read();
	int x=1,y=2,tt=0;
	int u=3,w=-1;
	for (int i=3;i<=n;i++)
	{
		int r=ask(x,y,i);
		if (r>w) w=r,u=i,tt=1;
		else if (r==w) tt++;
	}
	int v=-1,q=-1,tot=0;
	for (int i=1;i<=n;i++)
	{
		if (i==x||i==u) continue;
		int r=ask(x,u,i);
		if (r>q)
		{
			q=r,v=i,tot=1;
		}
		else if (r==q)
		{
			tot++;
		}
	}
	if (tot==1)
	{
		if (tt==n-2&&w==q) submit(x,y);
		else submit(v,u);
	}
	else
	{
		submit(u,x);
	}
}

int main()
{
	int t=read();
	while (t--) work(); 
	return 0;
}