// By: Little09
// Problem: CF1634F Fibonacci Additions
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1634F
// Memory Limit: 250 MB
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

const ll inf=1000000000000000000; 
//const ll mod=998244353;
//const ll mod=1000000007;

const int N=300005;
int n,m,mod; 
int a[N],tot;

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
int f[N];
int main()
{
	n=read(),m=read(),mod=read();
	for (int i=1;i<=n;i++) a[i]=read();
	f[1]=1,f[2]=1;
	for (int i=3;i<=n;i++) f[i]=(f[i-2]+f[i-1])%mod;
	for (int i=1;i<=n;i++) a[i]=(a[i]-read()+mod)%mod;
	for (int i=n;i>=2;i--) a[i]=((a[i]-a[i-1]-a[i-2])%mod+mod)%mod;
	for (int i=1;i<=n;i++) if (a[i]==0) tot++;
	for (int i=1;i<=m;i++)
	{
		int tp=readchar()-'A';
		if (tp==0) tp=1;
		else tp=-1;
		int l=read(),r=read();
		if (a[l]==0) tot--;
		a[l]=(a[l]+tp+mod)%mod;
		if (a[l]==0) tot++;
		if (r+1<=n)
		{
			if (a[r+1]==0) tot--;
			a[r+1]=((a[r+1]-f[r-l+2]*tp)%mod+mod)%mod;
			if (a[r+1]==0) tot++;
		}
		if (r+2<=n)
		{
			if (a[r+2]==0) tot--;
			a[r+2]=((a[r+2]-f[r-l+1]*tp)%mod+mod)%mod;
			if (a[r+2]==0) tot++;
		}
		if (tot==n) printYES;
		else printNO;
		
	}
	return 0;
}