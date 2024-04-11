#include <bits/stdc++.h>
using namespace std;

long long n;
int k;
char s[11];

int main()
{
	srand(time(0));
	scanf("%lld%d", &n, &k);
	long long l = 1, r = n;
	while (1)
	{
		while (r - l + 1 >= 40)
		{
//			printf("st %lld %lld\n", l, r);
			l = max(1ll, l - k); r = min(n, r + k);
//			printf("fix %lld %lld\n", l, r);
			long long mid = (l + r) / 2;
			printf("%lld %lld\n", l, mid);
			fflush(stdout);
			scanf("%s", s);
			if (s[0] == 'Y')
			{
				r = mid;
			} else {
				l = mid + 1;
			}
		}
		l = max(1ll, l - k); r = min(n, r + k);
		long long t = l + rand() % (r - l + 1);
		printf("%lld %lld\n", t, t);
		fflush(stdout);
		scanf("%s", s);
		if (s[0] == 'Y') return 0;
		l = max(1ll, l - k); r = min(n, r + k);
	}
	return 0;
}