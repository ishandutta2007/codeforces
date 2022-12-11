#include <stdio.h>
#include <vector>
#include <map>

#define LIMIT 100000

using namespace std;

map<long long, vector<long long> > MapDivisors;
int cnt = 0;

vector<long long>& divisors(long long x) {
	vector<long long>& ans1 = MapDivisors[x];
	if(!ans1.empty()) {
		return ans1;
	}
	vector<long long> ans2;
	for(long long i = 1;i * i <= x;i++) {
		if(x%i == 0) {
			ans1.push_back(i);
			if(i*i != x) {
				ans2.push_back(x/i);
			}
		}
	}
	ans1.insert(ans1.end(), ans2.rbegin(), ans2.rend());
	return ans1;
}
void dfs(long long x, long long k) {
	if(x == 1 || k == 0) {
		if(cnt >= LIMIT) {
			return;
		}
		printf("%I64d ", x);
		cnt++;
		return;
	}
	vector<long long>& r = divisors(x);
	for(int i = 0;i < (int)r.size();i++) {
		dfs(r[i], k-1);
		if(cnt >= LIMIT) {
			break;
		}
	}
}
int main() {
	long long x, k;
	scanf("%I64d%I64d", &x, &k);
	dfs(x, k);
	return 0;
}