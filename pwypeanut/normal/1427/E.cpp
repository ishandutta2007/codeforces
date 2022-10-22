#include <bits/stdc++.h>
using namespace std;

vector< pair< int, pair<int, int> > > memo[1000005];
set<long long> visited;
int cnt;

vector< pair<int, pair<long long, long long> > > answer;

void split(long long x) {
	visited.insert(x);
	if (x == 1) return;
	long long mn = 1000000000000000000ll;
	int best = -1;
	for (int i = 0; i < (1 << 10); i++) {
		long long xorsum = 0;
		for (int j = 0; j < 10; j++) {
			if (i & (1 << j)) xorsum ^= x * (j + 1);
		}
		if (xorsum % 2 == 0) continue;
		if (xorsum == x) continue;
		if (visited.find(xorsum) != visited.end()) continue;
		
		mn = min(mn, xorsum);
		if (xorsum == mn) best = i;
	}
	long long cur = 0;
	int prev = 1;
	for (int i = 0; i < 10; i++) {
		if (best & (1 << i)) {
			if (cur != 0) {
				for (int j = prev + 1; j <= i + 1; j++) {
					answer.push_back(make_pair(0, make_pair(x * (j - 1), x)));
					//printf("%lld + %lld\n", x * (j - 1), x);
					//cnt++;
				}
				prev = i + 1;
				answer.push_back(make_pair(1, make_pair(cur, x * (i + 1))));
				//printf("%lld ^ %lld\n", cur, x * (i + 1));
				//cnt++;
			}
			cur ^= x * (i + 1);
		}
	}
	if (mn < x) split(mn);
	else {
		answer.push_back(make_pair(0, make_pair(x, x)));
		answer.push_back(make_pair(1, make_pair(x, x + x)));
		//printf("%lld + %lld\n", x, x);
		//printf("%lld ^ %lld\n", x, x + x); 
		split(x ^ (x + x));
	}
}

int main() {
	int x;
	scanf("%d", &x);
	split(x);
	printf("%d\n", answer.size());
	for (int i = 0; i < answer.size(); i++) {
		if (answer[i].first == 0) printf("%lld + %lld\n", answer[i].second.first, answer[i].second.second);
		else 	printf("%lld ^ %lld\n", answer[i].second.first, answer[i].second.second);
	}
}