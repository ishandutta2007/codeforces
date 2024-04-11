// Author: Little09
// Problem: CF1689D Lena and Matrix
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1689D
// Memory Limit: 250 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mem(x) memset(x,0,sizeof(x))
#define printYes puts("Yes")
#define printYES puts("YES")
#define printNo puts("No")
#define printNO puts("NO")
#define endl "\n"
#define lowbit(x) (x&(-x))

const ll inf=1000000000000000000; 
//const ll mod=998244353;
//const ll mod=1000000007;

const int N=1000005;
int n,m; 

struct point
{
	int x,y;
}a[N],b[N],c[5],ans;
int cnta,cntb;
bool cmpx(point x,point y)
{
	return x.x<y.x;
}
bool cmpy(point x,point y)
{
	return x.y<y.y;
}

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
inline char readchar()
{
	char C=getchar();
    while (C<33||C>126) C=getchar();
    return C;
}
inline int raed(){return read();}
int calc(point u)
{
	int res=0;
	for (int i=1;i<=4;i++) res=max(res,max(abs(u.x-c[i].x),abs(u.y-c[i].y)));
	return res;
}
void work()
{
	n=read(),m=read(),cnta=0,cntb=0;
	for (int i=1;i<=n;i++) 
	{
		for (int j=1;j<=m;j++)
		{
			char x=readchar();
			if (x=='B')
			{
				a[++cnta].x=i+j,a[cnta].y=i-j;
				b[++cntb].x=i+j,b[cntb].y=i-j;
			}
		}
	}
	sort(a+1,a+cnta+1,cmpx);
	sort(b+1,b+cntb+1,cmpy);
	c[1]=a[1],c[2]=a[cnta],c[3]=b[1],c[4]=b[cntb];
	ans.x=2,ans.y=0;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			if (calc(ans)>calc((point){i+j,i-j})) ans.x=i+j,ans.y=i-j;
		}
	}
	printf("%d %d\n",(ans.x+ans.y)/2,(ans.x-ans.y)/2);
}

int main()
{
	int T=read();
	while (T--) work();
	return 0;
}