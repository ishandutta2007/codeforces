// By: Little09
// Problem: B. Build the Permutation
// Contest: Codeforces - Codeforces Round #758 (Div.1 + Div. 2)
// URL: https://codeforces.com/contest/1608/problem/B
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

const ll inf=1000000000000000000; 
//const ll mod=998244353;
//const ll mod=1000000007;

const int N=500005;
int n,m,T; 
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
inline char readchar()
{
	char C=getchar();
    while (C<33||C>126) C=getchar();
    return C;
}
inline int raed(){return read();}

void work()
{
	n=read();
	int x=read(),y=read();
	if (x+y>n-2)
	{
		cout << -1 << endl;
		return;
	}
	if (abs(x-y)>1)
	{
		cout << -1 << endl;
		return;
	}
	if (x==y)
	{
		int l=1,r=n;
		for (int i=1;i<=x;i++) 
		{
			printf("%d %d ",l,r);
			l++,r--;
		}
		for (int i=2*(x)+1;i<=n;i++)
		{
			printf("%d ",l);
			l++;
		}
	}
	else if (x==y+1)
	{
		int l=1,r=n;
		for (int i=1;i<=x;i++) 
		{
			printf("%d %d ",l,r);
			l++,r--;
		}
		for (int i=2*(x)+1;i<=n;i++)
		{
			printf("%d ",r);
			r--;
		}
	}
	else 
	{
		int l=1,r=n;
		for (int i=1;i<=y;i++) 
		{
			printf("%d %d ",n-l+1,n-r+1);
			l++,r--;
		}
		for (int i=2*(y)+1;i<=n;i++)
		{
			printf("%d ",n-r+1);
			r--;
		}
	}
	cout << endl;
	return;
}

int main()
{
	int tp=0;
	//0 : many test cases
	//1 : one test case
	if (tp==0) T=read();
	else T=1;
	while (T--)
	{
		work();
	}
	return 0;
}