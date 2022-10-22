#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mem(x) memset(x,0,sizeof(x))
//const ll inf=1000000000000000000; 

const int N=200001;
int n,T;
ll k; 
ll f[N];

inline int read()
{
	char C=getchar();
	int F=1,ANS=0;
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

inline ll F(ll x)
{
	if (x>61) x=61;
	return f[x];
}

void dfs(int x,ll y)
{
	if (x==n) return;
	ll res=0;
	for (int i=x+1;i<=n;i++)
	{
		if (res+F(n-i)>=y)
		{
			for (int j=i;j>=x+1;j--) cout << j << " ";
			dfs(i,y-res);
			return;
		}
		res+=F(n-i);
	}
}

void work()
{
	cin >> n >> k;
	if (n<=61&&k>f[n])
	{
		puts("-1");
		return;
	}
	dfs(0,k);
	puts("");
	return;
}

int main()
{
	f[0]=f[1]=1ll;
	for (int i=2;i<=61;i++) f[i]=f[i-1]*2ll;
	T=read();
	while (T--)
	{
		work();
	}
	return 0;
}