#include<cstdio>
#include<algorithm>

using namespace std;

int N, n, last[200000], pl[1000005], used[1000005];
long long a[200000], t[3000000], only[200000], k, ans = 0;
int mod = 1000000007;

long long sum (int l, int r) 
{
	if (l == r)
		return t[l];
	long long sz = 0;
	if (l % 2 == 1)
	{
		sz += t[l];
		l++;
	}
	if (l == r)
		return t[r] + sz;
	if (r % 2 == 0)
	{
		sz += t[r];
		r--;
	}
	if (l == r)
		return sz + t[l];
	sz += sum (l / 2, r / 2);
	return sz;
}

void update (int pos, int new_val) 
{
	int l = N + pos;
	while(l != 0)
	{
		t[l] = (t[l] + new_val) % mod;
		l /= 2;
	}	
}

int main()
{
	scanf("%d", &n);
	N = 1 << 20;
	for (int i = 0; i < n; i++)
		scanf("%I64d", &a[i]);
	only[0] = a[0];
	update(a[0], a[0]);
	for (int i = 1; i < n; i++)
	{
		only[i] = (((sum(N + 1, N + a[i]) + 1) % mod) * a[i]) % mod;
		k = ((only[i] - t[a[i] + N]) % mod + mod) % mod;
		update(a[i], k);
	}
	for (int i = n - 1; i >= 0; i--)
	    if (used[a[i]] == 0)
		{
			ans = (ans + only[i]) % mod;
			used[a[i]] = 1;
		}
	printf("%I64d\n", ans);
	return 0;
}