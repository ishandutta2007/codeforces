#include <cstdio>
#include <map>

typedef long long LL;

std::map<int, int> mp;

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		mp.clear();
		int N;
		scanf("%d", &N);
		int Sum = 0;
		LL Ans = 0;
		++mp[Sum];
		while (N--) {
			int x;
			scanf("%1d", &x);
			Sum += x - 1;
			Ans += mp[Sum];
			++mp[Sum];
		}
		printf("%lld\n", Ans);
	}
	return 0;
}