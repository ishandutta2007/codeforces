#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 2e5 + 7;
priority_queue<int> q; 
ll ans = 0;
int main() {
	int n; scanf("%d", &n);
	while(n--) {
		int x; scanf("%d", &x);
		q.push(-x), q.push(-x);
		ans += q.top() + x, q.pop();
	}
	printf("%lld\n", ans);
	return 0;
}