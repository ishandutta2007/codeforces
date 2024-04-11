#include <bits/stdc++.h>

#define N 500005

#define pb push_back
#define mk make_pair
#define fi first
#define se second

using namespace std;

char c[N];

long long pw[N], last[N], j;

void Main()
{
	int n, k; long long x; string ans;
	scanf("%d%d%lld", &n, &k, &x);
	scanf("%s", c + 1); pw[n + 1] = 1;
	for (int i = n; i >= 1; i = j)
	if (c[i] == '*')
	{
		long long s = 0;
		for (j = i; j >= 1 && c[j] == '*'; --j) s += k;
		pw[j + 1] =0;
		for (int k = 0; k <= s; ++k) pw[j + 1] = min(pw[j + 1] + pw[i + 1], x);
//		pw[j + 1] = min(1ll * (s + 1) * pw[i + 1], x);
	}
	else pw[i] = pw[i + 1], j = i - 1;
	for (int i = 1; i <= n; i = j)
		if (c[i] == '*') 
		{
			int s = 0;
			for (j = i; j <= n && c[j] == '*'; ++j) s += k;
			for (int k = 0; k <= s; ++k)
				if (x > pw[j]) x -= pw[j], ans += 'b';
				else break;
		}
		else ans += c[i], j = i + 1;
	cout << ans << endl; 
}

int main()
{
	int T;
	scanf("%d", &T); for (;T--;) Main(); 
}