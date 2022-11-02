#include <cstdio>
#include <vector>
std::vector<int> a;
int main() {
	register long long p;
	register int k, i, tmp;
	scanf("%lld%d", &p, &k);
	for(i = 0; p; ++i) {
		tmp = (p % k + k) % k;
		p = (tmp - p) / k;
		a.push_back(tmp);
	}
	printf("%d\n", a.size());
	for(i = 0; i < a.size(); ++i) printf("%d ", a[i]);
	return 0;
}