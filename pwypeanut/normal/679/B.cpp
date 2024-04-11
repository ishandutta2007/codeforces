#include <bits/stdc++.h>
using namespace std;

long long X, value;

vector<long long> v;

long long findans(long long tmp, int after) {
	long long ori = tmp;
	long long ans = 0;
	for (long long i = 1; i <= after; i++) {
		long long val = i * i * i;
		long long next_val = (i + 1) * (i + 1) * (i + 1);
		long long max_dig = (next_val - (ori - tmp) - 1) / val;
		long long act_dig = min(max_dig, tmp / val);
		tmp -= act_dig * val;
		ans += act_dig;
		for (int j = 0; j < act_dig; j++) v.push_back(i);
	}
	value = X - tmp;
	return ans;
}

bool attempt(int x) {
	v[x]++;
	long long sum = 0;
	for (int i = v.size() - 1; i >= 0; i--) {
		sum += v[i] * v[i] * v[i];
		if (sum >= (v[i] + 1) * (v[i] + 1) * (v[i] + 1)) {
			v[x]--;
			return false;
		}
	}
	v[x]--;
	return true;
}

int main() {
	scanf("%lld", &X);
	long long real_ans = findans(X, 100000);
	reverse(v.begin(), v.end());
	//for (int i = 0; i < v.size(); i++) printf("%d ", v[i]);
	//printf("\n");
	for (int i = 0; i < v.size(); i++) {
		while (value + (v[i] + 1) * (v[i] + 1) * (v[i] + 1) - v[i] * v[i] * v[i] <= X) {
			if (attempt(i)) {
				value += (v[i] + 1) * (v[i] + 1) * (v[i] + 1) - v[i] * v[i] * v[i];
				v[i]++;
			} else break;
		}
	}
	//for (int i = 0; i < v.size(); i++) printf("%d ", v[i]);
	//printf("\n");
	printf("%lld %lld\n", real_ans, value);
}