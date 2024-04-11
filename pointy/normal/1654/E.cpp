// By: Little09
// Problem: E. Arithmetic Operations
// Contest: Codeforces - Codeforces Round #778 (Div. 1 + Div. 2, based on Technocup 2022 Final Round)
// URL: https://codeforces.ml/contest/1654/problem/E
// Memory Limit: 1024 MB
// Time Limit: 5000 ms
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

const int N=100005,B=321,K=N*B+2*N;
int n,m,ans; 
int a[N];

int b[N*B*2+4*N],c[N];

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

int main()
{
	n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=-B;i<=B;i++)
	{
		for (int j=1;j<=n;j++)
		{
			b[a[j]-i*j+K]++;
			ans=max(ans,b[a[j]-i*j+K]);
		}
		for (int j=1;j<=n;j++)
		{
			b[a[j]-i*j+K]--;
		}
	}
	for (int i=1;i<=n;i++)
	{
		int r=min(n,i+B);
		for (int j=i+1;j<=r;j++)
		{
			int det=a[j]-a[i],len=j-i;
			if (det%len!=0) continue;
			int k=det/len;
			b[k+K]++;
			ans=max(ans,b[k+K]+1);
		}
		for (int j=i+1;j<=r;j++)
		{
			int det=a[j]-a[i],len=j-i;
			if (det%len!=0) continue;
			int k=det/len;
			b[k+K]--;
		}
	}
	cout << n-ans;
	return 0;
}