#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<set>
#include<map>
#include<iostream>

#define fi first
#define se second
#define mk make_pair
#define pb push_back

#define ls (t<<1)
#define rs ((t<<1)|1)
#define mid ((l+r)>>1)

#define N 1000005
#define Mo 1000000007

using namespace std;

int F[N],fac[N],inv[N], n, ans;

int power(int x,int y)
{
	int s = 1;
	for (;y;y>>=1,x=1ll*x*x%Mo) if (y&1) s=1ll*s*x%Mo;
	return s;
}

int C(int x,int y)
{
	if (y < 0) return 0;
	if (x < y) return 0; 
	return 1ll * fac[x] * inv[y] % Mo * inv[x - y]%Mo;
}

int main()
{
	scanf("%d",&n);
	fac[0] = 1;
	for (int i = 1; i <= n; ++i) fac[i] = 1ll * fac[i - 1] * i %Mo;
	for (int i = 0; i <= n; ++i) inv[i] = power(fac[i], Mo - 2); 
	for (int i = 2; i < n; i += 2) ans = (ans + 2ll * (C(i, n - i) + C(i - 1, n - i - 1)) * fac[i] % Mo) % Mo;
	if (n % 2 == 0) ans = (ans + 2ll * fac[n] %Mo) %Mo;
	printf("%d\n", ans); 
}