// Author: Little09
// Problem: B. Integers Have Friends
// Contest: Codeforces Round #736 (Div. 1)
// URL: https://codeforces.com/contest/1548/problem/B
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
#define endl "\n"
#define lowbit(x) (x&(-x))

const ll inf=1000000000000000000; 
//const ll mod=998244353;
//const ll mod=1000000007;

const int N=500005;
int n,m; 
ll a[N],b[N],resl[N],resr;

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
	n=read();
	for (int i=1;i<=n;i++) b[i]=read();
	if (n==1)
	{
		printf("1\n");
		return;
	}
	for (int i=1;i<n;i++) a[i]=abs(b[i+1]-b[i]);
	n--;
	ll l=1,r=1,mid=1,ans=(a[1]!=1);
	resl[1]=a[1];
	if (a[1]==1) l=mid+1;
	while (r<n)
	{
		r++;
		if (r==mid+1) resr=a[r];
		else resr=__gcd(resr,a[r]);
		while (l<=mid&&__gcd(resl[l],resr)==1) l++;
		if (l>mid)
		{
			mid=r,l=r+1,resl[l]=a[r];
			while (l>1)
			{
				resl[l-1]=__gcd(a[l-1],resl[l]);
				if (resl[l-1]>1) l--;
				else break;
			}
		}
		ans=max(ans,r-l+1);
	}
	printf("%d\n",ans+1);
}

int main()
{
	int T=read();
	while (T--) work();
	return 0;
}