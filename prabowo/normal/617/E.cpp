#include <cstdio>
#include <cmath>
#include <utility>
#include <algorithm>

using namespace std;

const int N = 100000;

typedef pair <int, int> pii;

int S;
int pre[N + 1];
pair <int, pii> query[N];
int cnt[1 << 20];
pair <int, long long> answer[N];

bool cmp (pair <int, pii> x, pair <int, pii> y) {
	if (x.second.first / S == y.second.first / S) return x.second.second < y.second.second;
	return x.second.first < y.second.first;
}

int main () {
	int n, m, k;
	scanf ("%d %d %d", &n, &m, &k);
	S = (int) sqrt (n + 1);
	
	for (int i = 0; i < n; i++) {
		scanf ("%d", pre + i + 1);
		pre[i + 1] ^= pre[i];
	}
	
	for (int i = 0; i < m; i++) {
		scanf ("%d %d", &query[i].second.first, &query[i].second.second);
		query[i].second.first--;
		query[i].first = i;
	}
	
	sort (query, query + m, cmp);
	
	int l = 1;
	int r = 0;
	
	long long ans = 0;
	for (int i = 0; i < m; i++) {
		while (l < query[i].second.first) {
			cnt[pre[l]]--;
			ans -= cnt[ k ^ pre[l++] ];
		}
		
		while (l > query[i].second.first) {
			ans += cnt[ k ^ pre[--l] ];
			cnt[pre[l]]++;
		}
		
		while (r < query[i].second.second) {
			ans += cnt[k ^ pre[++r] ];
			cnt[pre[r]]++;
		}
		
		while (r > query[i].second.second) {
			cnt[pre[r]]--;
			ans -= cnt[k ^ pre[r--]];
		}
		
		answer[i] = make_pair (query[i].first, ans);
	}
	
	sort (answer, answer + m);
	
	for (int i = 0; i < m; i++) printf ("%I64d\n", answer[i].second);
	
	return 0;
}