// By: Little09
// Problem: D. Flipping Range
// Contest: Codeforces - Codeforces Round #768 (Div. 1)
// URL: https://codeforces.com/contest/1630/problem/D
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

const int N=1000005;
int n,m; 
ll a[N];

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
vector<ll>b[N];
int c;
ll d[N];
void work()
{
	n=read(),m=read();
	
	ll sum=0,ans;
	for (int i=1;i<=n;i++) a[i]=read(),sum+=a[i];
	int x=0;
	ans=sum;
	for (int i=1;i<=m;i++) x=__gcd(x,read());
	for (int i=1;i<=x;i++) b[i].clear(),d[i]=inf;
	int res=1;
	for (int i=1;i<=n;i++)
	{
		b[res].push_back(a[i]);
		d[res]=min(d[res],abs(a[i]));
		res++;
		if (res==x+1) res=1;
	}
	c=0;
	for (int i=1;i<=x;i++) c=max(c,(int)b[i].size());
	for (int i=1;i<=x;i++) sort(b[i].begin(),b[i].end());
	for (int i=0;i<c;i++)
	{
		for (int j=1;j<=x;j++)
		{
			if (b[j].size()>i&&b[j][i]<0) sum-=2*b[j][i];
			else sum-=2*d[j],d[j]*=-1;
		}
 		ans=max(ans,sum);
	}
	cout << ans << endl;
}

int main()
{
	int T=read();
	while (T--) work();
	return 0;
}