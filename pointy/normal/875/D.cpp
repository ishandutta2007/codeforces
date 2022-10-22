// By: Little09
// Problem: CF875D High Cry
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF875D
// Memory Limit: 500 MB
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

int f[N][25],g[N][25];
void STwork()
{
	for (int i=1;i<=n;i++) f[i][0]=a[i];
	for (int i=1;i<=n;i++) g[i][0]=a[i];
	int t=log(n)/log(2);
	for (int j=1;j<=t;j++)
	{
		for (int i=1;i<=n-(1<<j)+1;i++)
		{
			f[i][j]=max(f[i][j-1],f[i+(1<<(j-1))][j-1]);
			g[i][j]=(g[i][j-1]|g[i+(1<<(j-1))][j-1]);
		}
	}
}
inline int askmax(int l,int r)
{
	int k=log(r-l+1)/log(2);
	return max(f[l][k],f[r-(1<<k)+1][k]);
}
inline int askor(int l,int r)
{
	int k=log(r-l+1)/log(2);
	return (g[l][k]|g[r-(1<<k)+1][k]);
}
bool check(int l,int r,int x,int tp)
{
	if (askmax(l,r)!=x) return 0;
	if (askor(l,r)!=x) return 0;
	if (tp==1&&l<r&&askmax(l+1,r)==x) return 0;
	return 1;
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



int main()
{
	n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	ll ans=0;
	STwork();
	for (int i=1;i<=n;i++)
	{
		ll res=0;
		int l=1,r=i;
		while (l<=r)
		{
			int mid=(l+r)>>1;
			if (check(mid,i,a[i],0)) r=mid-1;
			else l=mid+1;
			//cout << l << " " << r << endl;
		}
		//cout << l << endl;
		res=i-l+1;
		l=i,r=n;
		while (l<=r)
		{
			int mid=(l+r)>>1;
			if (check(i,mid,a[i],1)) l=mid+1;
			else r=mid-1;
			//cout << l << " " << r << endl;
		}
		res=res*(r-i+1);
		ans+=res;
	}
	ans=1ll*n*(n+1)/2-ans;
	cout << ans;
	return 0;
}