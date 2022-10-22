// By: Little09
// Problem: CF980D Perfect Groups
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF980D
// Memory Limit: 2100 MB
// Time Limit: 250000 ms
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
#define lowbit(x) (x&(-x))

const ll inf=1000000000000000000; 
//const ll mod=998244353;
//const ll mod=1000000007;

const int N=5005;
int n,m; 
int a[N],ans[N];

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

bool b[N];
map<int,int>q;

int main()
{
	n=read();
	for (int i=1;i<=n;i++) 
	{
		a[i]=read();
		for (int j=2;j<=sqrt(abs(a[i]));j++)
		{
			while (a[i]%(j*j)==0) a[i]/=(j*j);
		}
	}
	int cnt=1;
	q[0]=1;
	for (int j=1;j<=n;j++) 
	{
		if (q[a[j]]==0) q[a[j]]=++cnt;
		a[j]=q[a[j]];
	}
	for (int i=1;i<=n;i++)
	{
		mem(b);
		b[1]=1;
		int tot=0;
		for (int j=i;j<=n;j++)
		{
			if (b[a[j]]==0) tot++;
			b[a[j]]=1;
			ans[tot]++;
		}
	}
	ans[1]+=ans[0];
	for (int i=1;i<=n;i++) printf("%d ",ans[i]);
	return 0;
}