// By: Little09
// Problem: E. notepad.exe
// Contest: Codeforces Global Round 20
// URL: https://codeforces.com/contest/1672/problem/E
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

bool check(int x)
{
	printf("? %d\n",x);
	fflush(stdout);
	int op=read();
	if (op!=1) return 1;
	return 0;
}

int main()
{
	n=read();
	int l=1,r=2000*2000;
	while (l<=r)
	{
		int mid=(l+r)>>1;
		if (check(mid)) l=mid+1;
		else r=mid-1;
	}
	int ans=2000*2000;
	for (int i=1;i<=n;i++)
	{
		printf("? %d\n",(l+i)/i-1);
		fflush(stdout);
		int x=read();
		if (x==0) continue;
		ans=min(ans,x*((l+i)/i-1));
	}
	printf("! %d",ans);
	return 0;
}