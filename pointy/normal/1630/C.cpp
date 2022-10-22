// By: Little09
// Problem: C. Paint the Middle
// Contest: Codeforces - Codeforces Round #768 (Div. 1)
// URL: https://codeforces.com/contest/1630/problem/C
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
int n,m; 
int a[N],b[N],c[N];
 
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
struct point
{
	int l,r;
}w[N],r[N];
int cnt,tot,ans,d[N];
bool cmp(point x,point y)
{
	if (x.l==y.l) return x.r>y.r;
	return x.l<y.l;
}
int main()
{
	n=raed();
	for (int i=1;i<=n;i++) a[i]=raed();
	for (int i=1;i<=n;i++) b[i]=n+1,c[i]=0;
	for (int i=1;i<=n;i++) b[a[i]]=min(b[a[i]],i);
	for (int i=1;i<=n;i++) c[a[i]]=max(c[a[i]],i);
	for (int i=1;i<=n;i++) 
	{
		if (b[i]==n+1) continue;
		if (b[i]==c[i]) continue;
		cnt++;
		w[cnt].l=b[i],w[cnt].r=c[i];
	}
	sort(w+1,w+cnt+1,cmp);
	int las=0;
	for (int i=1;i<=cnt;i++)
	{
		if (w[i].l>las)
		{
			ans--;
			ans+=w[i].r-w[i].l;
			las=w[i].r;
		}
		else
		{
			int res=0;
			while (w[i].l<=las&&i<=cnt)
			{
				res=max(res,w[i].r);
				i++;
			}
			i--;
			if (res<=las) continue;
			ans--,ans+=res-las,las=res;
		}
	}
	cout << ans;
	return 0;
}