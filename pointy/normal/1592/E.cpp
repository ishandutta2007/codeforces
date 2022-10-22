// By: Little09
// Problem: E. Bored Bakry
// Contest: Codeforces - Codeforces Round #746 (Div. 2)
// URL: https://codeforces.com/contest/1592/problem/E
// Memory Limit: 256 MB
// Time Limit: 4000 ms
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

const ll inf=1000000000000000000; 
//const ll mod=998244353;
//const ll mod=1000000007;

const int N=1e6+5,M=4e6+5;
int n,m,ans; 
int a[N],b[N],c[N],d[M];
int t[N],cnt;
void add(int x,int y)
{
	t[++cnt]=x;
	d[x]=min(d[x],y);
}
void update(int x,int y)
{
	ans=max(ans,y-d[x]);
}
void clear()
{
	for (int i=1;i<=cnt;i++) d[t[i]]=1e9;
	cnt=0;
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

void work(int id)
{
	for (int i=1;i<=n;i++) b[i]=(((1<<id)&a[i])!=0);
	for (int i=1;i<=n+1;i++)
	{
		if (i==n+1||b[i]==0)
		{
			clear();
		}
		else
		{
			add(c[i-1],i-1);
			update(c[i],i);
		}
	}
	for (int i=1;i<=n;i++) b[i]=b[i-1]^b[i];
	for (int i=1;i<=n;i++) c[i]=c[i]*2+b[i];
}

int main()
{
	n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<=n;i++) c[i]=i%2;
	for (int i=0;i<=4e6;i++) d[i]=1e9;
	for (int i=20;i>=0;i--) work(i);
	cout << ans;
	return 0;
}