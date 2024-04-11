#include <bits/stdc++.h>

#define N 500005

#define pb push_back
#define mk make_pair
#define fi first
#define se second

using namespace std;

long long a[N];
int n, k;

void Main()
{
	//[k - ps, k - 1]
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; ++i) scanf("%lld", &a[i]), a[i] += a[i - 1];
	int ps = min(k, n);
	long long w = 0;
	for (int i = 1; i + ps - 1 <= n; ++i) w = max(w, a[i + ps - 1] - a[i - 1]);
	printf("%lld\n", w + 1ll * (k - ps + k - 1) * ps / 2);
	
}

int main()
{
	int t;
	scanf("%d", &t);
	for (;t--;) Main();
}