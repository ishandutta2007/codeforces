#include <bits/stdc++.h>

#define N 500005

#define pb push_back
#define mk make_pair
#define fi first
#define se second

using namespace std;

int n, a[N];

void Main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n / 2; ++i) printf("%d %d\n", a[n - i + 1], a[1]);	
}

int main()
{
	int T; scanf("%d", &T);
	for (;T--;) Main();
}