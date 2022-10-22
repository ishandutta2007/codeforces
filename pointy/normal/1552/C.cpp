// By: Little09
// Problem: C. Maximize the Intersections
// Contest: Codeforces Global Round 15
// URL: https://codeforces.com/contest/1552/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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

const int N=205;
int n,m; 
int a[N],b[N],c[N],d[N],cnt;

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

void work()
{
	n=read(),m=read();
	mem(a);
	for (int i=1;i<=m;i++) 
	{
		int x=read(),y=read();
		a[x]=1,a[y]=1;
		b[i]=x,c[i]=y;
		if (b[i]>c[i]) swap(b[i],c[i]);
	}
	cnt=0;
	for (int i=1;i<=2*n;i++)
	{
		if (a[i]==0) d[++cnt]=i;
	}
	for (int i=1;i<=cnt/2;i++)
	{
		++m;
		b[m]=d[i],c[m]=d[i+cnt/2];
		if (b[m]>c[m]) swap(b[m],c[m]);
	}
	int ans=0;
	for (int i=1;i<=m;i++)
	{
		for (int j=1;j<=m;j++)
		{
			if (b[i]<b[j]&&b[j]<c[i]&&c[i]<c[j]) ans++;
			
		}
	}
	cout << ans << endl;
}

int main()
{
	int T=read();
	while (T--) work();
	return 0;
}