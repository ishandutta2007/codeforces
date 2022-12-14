#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<set>
#include<map>
#include<cstring>
#include<string>
#include<cstdlib>
#include<ctime>
#include<cassert>

using namespace std;

#define FNAME ""
#define FILE 0

#define pb push_back
#define mp make_pair
#define LL long long
#define ULL unsigned long long
#define LD long double

#ifdef WIN32
	#define I64 "%I64d"
#else
	#define I64 "%lld"
#endif

string s, t, r;
int n, k, a[30], sum[10005], N, ll, rr, z[10005], max1, l, ans;

int main()
{
	#if (FILE == 1)
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout);
	#endif
	cin >> s;
	n = s.length();
	cin >> t;
	scanf("%d", &k);
	for (int i = 0; i < 26; i++)
		a[i] = t[i] - '0';
	for (int i = 1; i <= n; i++)
		sum[i] = sum[i - 1] + (1 - a[s[i - 1] - 'a']); 
	for (int g = 0; g < n; g++)
	{
		r = "";
		for (int j = g; j >= 0; j--)
			r += s[j];
		r += '$';
		for (int j = n - 1; j >= 0; j--)
			r += s[j];
		N = r.length();
		ll = rr = 0;
		for (int i = 1; i < N; i++)
		{
			z[i] = 0;
			if (i <= rr)
				z[i] = min(z[i - ll], rr - i + 1);
			while(i + z[i] < N && r[z[i]] == r[i + z[i]])
				z[i]++;
			if (i + z[i] - 1 > rr)
			{
				ll = i;
				rr = i + z[i] - 1;	
			}
		}
		max1 = 0;
		for (int i = N - 1; i >= N - g; i--)
		 	max1 = max(max1, z[i]);
		l = -1;
		for (int i = 0; i <= g; i++)
			if (sum[g + 1] - sum[i] > k)
				l = i;
		ans += max(0, g - l - max1);
	}
	printf("%d\n", ans);
	return 0;
}