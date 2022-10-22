// By: Little09
// Problem: C. Banknotes
// Contest: Codeforces - Educational Codeforces Round 116 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1606/problem/C
// Memory Limit: 256 MB
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

const ll inf=1000000000000000000; 
//const ll mod=998244353;
//const ll mod=1000000007;

const int N=500005;
ll n,m,T; 
int a[N],b[N];
ll c[N],ans[N];

inline ll read()
{
    ll F=1,ANS=0;
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
	n=read(),m=read()+1;
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<=n;i++)
	{
		if (i<n) b[i]=a[i+1]-a[i];
		else b[i]=9;
		c[i]=pow(10,b[i])-1;
	}
	for (int i=n;i>=1;i--)
	{
		ll sum=0;
		for (int j=1;j<i;j++) sum+=c[j];
		if (sum>m)
		{
			ans[i]=0;
			continue;
		}
		ans[i]=m-sum;
		m=sum;
	}
	bool flag=0;
	for (int i=n;i>=1;i--)
	{
		if (flag==1||ans[i]>0)
		{
			flag=1;
			printf("%lld",ans[i]);
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