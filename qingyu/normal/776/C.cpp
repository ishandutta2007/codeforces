#include <bits/stdc++.h>

typedef long long ll;
const int N = 1e6 + 50;
const ll upbound = 1e16;

/* map too slow
#if __cplusplus >= 201103
std::unordered_map<ll, int> map;
#else
std::map<ll, int> map;
#endif
*/

int n, k, a[N];
ll S[N];
std::vector<ll> calcs;

const int B = 3000007;
struct hash_table
{
	std::queue<int> que;
	int head[B], nxt[B], c[B], cnt; 
	ll ver[B];
	inline int id(ll x)
	{
		return (x % B + B) % B;
	}
	inline int get(ll x)
	{
		int u = id(x);
		for (int i = head[u]; i; i = nxt[i])
			if (ver[i] == x)
				return i;
		return -1;
	}
	inline void ins(ll x)
	{
		int u = id(x);
		nxt[++cnt] = head[u];
		ver[cnt] = x;
		c[cnt] = 1;
		head[u] = cnt;
	}
	inline void add(ll x)
	{
		int z = get(x);
		if (z == -1) ins(x);
		else ++c[z];
	}
	inline int val(ll x)
	{
		int z = get(x);
		if (z == -1) return 0;
		return c[z];
	}
	inline void clear()
	{
		memset(head, 0, sizeof head);
		cnt = 0;
	}
} ht;

inline ll qabs(ll x)
{
	return x >= 0 ? x : -x;
}

inline char nc()
{
	static char buf[1000000], *p1 = buf, *p2 = buf;
	return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1000000, stdin), p1 == p2) ? EOF : *p1++;
}

inline int read()
{
	int res = 0, neg = 1;
	char ch;
	do 
	{
		ch = nc();
		if (ch == '-') neg = -1;
	} while (ch < 48 || ch > 57);
	do res = res * 10 + ch - 48, ch = nc(); while (ch >= 48 && ch <= 57);
	return res * neg;
}

int main()
{  
	n = read(), k = read();
	for (int i = 1; i <= n; ++i) a[i] = read(), S[i] = S[i - 1] + a[i];
	calcs.clear();
	for (ll z = 1; qabs(z) <= upbound && calcs.size() <= 50; z *= k) calcs.push_back(z);
	std::sort(calcs.begin(), calcs.end());
	calcs.erase(std::unique(calcs.begin(), calcs.end()), calcs.end());
	
	ht.clear(); ht.add(0);
	ll ans = 0;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 0; j < calcs.size(); ++j) ans += ht.val(S[i] - calcs[j]);
		ht.add(S[i]);
	}	
	printf("%lld\n", ans);
	
	return 0;
}