#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5; 

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

bool check(int n)
{
	for (;n;n/=2) if (n%2==0) return 0;
	return 1;
}
int fa[N];

signed main()
{
	int n=read(),k=read();
	if (n%2==0) return puts("NO"),0;
	if (k==0)
	{
		if (!check(n)) return puts("NO"),0;
		puts("YES");
		for (int i=1;i<=n;i++) print(i/2," \n"[i==n]);
		return 0;
	}
	if (k>(n-3)/2) return puts("NO"),0;
	if (k==1&&check(n-(k-1)*2)) return puts("NO");
	if (k==2&&n<=9&&check(n-(k-1)*2)) return puts("NO");
	int m=n-(k-1)*2;
	if (check(n-(k-1)*2))
	{
		m-=2;
		fa[n]=n-3,fa[n-1]=n-3;
		for (int i=n-3;i>m;i--) fa[i]=i+1+(i&1);
	}
	else for (int i=n-1;i>m;i--) fa[i]=i+1+(i&1);
	for (int i=1;i<=m;i++) fa[i]=i/2;
	if (m<n) fa[1]=m+2;
	puts("YES");
	for (int i=1;i<=n;i++) print(fa[i]," \n"[i==n]);
	
	return 0;
}