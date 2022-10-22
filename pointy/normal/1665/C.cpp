// By: Little09
// Problem: C. Tree Infection
// Contest: Codeforces - Codeforces Round #781 (Div. 2)
// URL: https://codeforces.com/contest/1665/problem/C
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
inline char readchar()
{
	char C=getchar();
    while (C<33||C>126) C=getchar();
    return C;
}
inline int raed(){return read();}

bool check(int x)
{
	int tot=x,res=0;
	for (int i=n;i>=1;i--)
	{
		if (a[i]==0) continue;
		res++;
		if (a[i]-tot>0) res+=a[i]-tot;
		tot--;
	}
	if (res<=x) return 1;
	return 0;
}

void work()
{
	n=read();
	for (int i=1;i<=n;i++) a[i]=0;
	for (int i=1;i<n;i++) a[read()]++;
	a[++n]=1;
	sort(a+1,a+n+1);
	int l=1,r=n;
	while (l<=r)
	{
		int mid=(l+r)>>1;
		if (check(mid)) r=mid-1;
		else l=mid+1;
	}
	cout << l << endl;
}

int main()
{
	int T=read();
	while (T--) work();
	return 0;
}