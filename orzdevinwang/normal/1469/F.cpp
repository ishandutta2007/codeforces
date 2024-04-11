#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 4e5 + 7;
const int MAXN = 1e9;
int n, l[N], now = 2;
ll Sum = 0, k, s[N], sum;
int main() {
	scanf("%d%lld", &n, &k), Sum = - 2 * (n - 1) - 1;
	L(i, 1, n) scanf("%d", &l[i]), Sum += l[i];
	if(Sum < k) return puts("-1"), 0;
	sort(l + 1, l + n + 1), reverse(l + 1, l + n + 1);
	++ s[2], -- s[2 + (l[1] - 1) / 2];
	++ s[2], -- s[2 + l[1] / 2];
	L(i, 1, 1e9) {
		s[i] += s[i - 1], sum += s[i];
		if(sum + s[i + 1] + s[i] >= k) {
			printf("%d\n", i + 1);
			return 0;
		}
		while(s[i] && now <= n) {
			--sum, -- s[i], ++ s[i + 1];
			++ s[i + 2], -- s[i + 2 + (l[now] - 1) / 2];
			++ s[i + 2], -- s[i + 2 + l[now] / 2];
			++ now;
		}
	}
	assert(0);
	return 0;
}