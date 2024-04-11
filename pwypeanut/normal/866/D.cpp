#include <bits/stdc++.h>
using namespace std;

set<int> S;
map<int, int> M;
int N;

int main() {
	scanf("%d", &N);
	long long ans = 0;
	for (int i = 0; i < N; i++) {
		int x;
		scanf("%d", &x);
		set<int>::iterator it = S.begin();
		if (it == S.end() || *it >= x) {
			M[x]++;
			S.insert(x);
			continue;
		}
		ans += x - *it;
		M[*it]--;
		M[x]+=2;
		if (M[*it] <= 0) S.erase(it);
		S.insert(x);
	}
	printf("%lld\n", ans);
}