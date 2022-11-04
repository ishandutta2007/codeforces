#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define sz(x) (int) x.size()

const int INF = 1e9;
const ll LINF = 1e18;

const int MEM = 2e8;

char mem[MEM];
int mem_ptr;

void* operator new(size_t s) {
    void* res = &mem[mem_ptr];
    mem_ptr += s;
    return res;
}

void operator delete(void* s) {}

const int N = 1e6 + 123;

int n, k;
int dp[N];
int c[N];

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &c[i]);
	}
	
	fill(dp, dp + N, -1);
	vector<int> primes;
	for (int i = 2; i < N; i++) {
		if (dp[i] == -1) {
			dp[i] = i;
			primes.push_back(i);
		}
		
		for (int p : primes) {
			if (p > dp[i] || p * 1LL * i >= N) break;
			dp[p * i] = p;
		}
	}
		
	map<int, int> our;
	map<int, int> best;
	
	{
		int x = k;
		while (x != 1) {
			int d = dp[x];
			our[d]++;
			x /= d;
		}
	}
	
	for (int i = 0; i < n; i++) {
		map<int, int> cur;
		int x = c[i];
		while (x != 1) {
			int d = dp[x];
			cur[d]++;
			x /= d;
		}
		
		for (auto &it : cur) {
			best[it.first] = max(best[it.first], it.second);
		}
	}
	
	bool ok = true;
	
	for (auto &it : our) {
		if (best[it.first] < it.second) ok = false;
	}
	
	cout << (ok ? "Yes\n" : "No\n");
	
	return 0;
}