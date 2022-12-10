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

#define N 200005

using namespace std;

int n,m,i;

long long a[N],b[N];

long long gcd(long long a,long long b)
{
	return !b?a:gcd(b,a%b);
}

int main()
{
	scanf("%d%d",&n,&m);
	for (i=1;i<=n;++i) scanf("%I64d",&a[i]);
	for (i=1;i<=m;++i) scanf("%I64d",&b[i]);
	sort(a+1,a+n+1);
	for (i=2;i<=n;++i) a[i]-=a[1];
	long long g=0;
	for (i=2;i<=n;++i) g=gcd(a[i],g);
	for (i=1;i<=m;++i) printf("%I64d ",gcd(a[1]+b[i],g));
}