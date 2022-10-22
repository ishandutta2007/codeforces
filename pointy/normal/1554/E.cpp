// By: Little09
// Problem: E. You
// Contest: Codeforces - Codeforces Round #735 (Div. 2)
// URL: https://codeforces.com/contest/1554/problem/E
// Memory Limit: 256 MB
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

const ll inf=1000000000000000000; 
const ll mod=998244353;
//const ll mod=1000000007;

const int N=300015;
int n,m,T; 
int a[N];
int t[N],nxt[N],cnt,h[N];
ll ans[N];
void add(int x,int y)
{
	t[++cnt]=y;
	nxt[cnt]=h[x];
	h[x]=cnt;
}
ll ksm(ll x,ll y)
{
	ll res=1;
	while (y)
	{
		if (y&1) res=res*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return res;
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
bool flag;
void dfs(int x,int fa,int y)
{
	if (flag==1) return;
	for (int i=h[x];i;i=nxt[i])
	{
		if (t[i]!=fa) dfs(t[i],x,y);
	}
	if (a[x]%y==0) 
	{
		if (fa!=0) a[fa]++;
		return;
	}
	if ((a[x]+1)%y==0&&fa!=0) return;
	flag=1;
}
void work()
{
	n=read();
	cnt=0,flag=0;
	//mem(a);
	for (int i=0;i<=2*n+1;i++) t[i]=0,nxt[i]=0,h[i]=0,ans[i]=0;
	for (int i=1;i<n;i++)
	{
		int x=read(),y=read();
		add(x,y),add(y,x);
	}
	for (int i=1;i<=n;i++)
	{
		if ((n-1)%i==0) 
		{
			if (i==1) ans[i]=ksm(2,n-1);
			else 
			{
				for (int j=0;j<=n;j++) a[j]=0;
				flag=0;
				dfs(1,0,i);
				if (flag==0) ans[i]=1;
				else ans[i]=0;
			}
		}
		else ans[i]=0;
	}
	for (int i=n;i>=1;i--)
	{
		for (int j=2;i*j<=n;j++)
		{
			ans[i]-=ans[i*j];
			ans[i]%=mod;
			ans[i]=(ans[i]+mod)%mod;
		}
	}
	for (int i=1;i<=n;i++) printf("%lld ",ans[i]);
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