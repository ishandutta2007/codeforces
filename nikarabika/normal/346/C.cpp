//sobskdrbhvk
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define sz(x) ((int)(x).size())
#define smax(x, y) ((x) = max((x), (y)))
#define smin(x, y) ((x) = min((x), (y)))
#define all(x) x.begin(),x.end()
#define div Div

const int maxn = 1e6 + 85 - 69;
int x[maxn],
	dp[maxn],
	div[maxn],
	a, b, n;
deque<int> dq;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	memset(div, -1, sizeof div);
	memset(dp, 63, sizeof dp);
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> x[i];
	cin >> a >> b;
	sort(x, x + n);
	n = unique(x, x + n) - x;
	for(int i = 0; i < n; i++){
		int ptr = b + ((x[i] - (b % x[i])) % x[i]);
		while(ptr <= a){
			smax(div[ptr - b], x[i]);
			ptr += x[i];
		}
	}
	dp[0] = 0;
	if(~div[0])
		dq.push_back(0);
	for(int i = b+1; i <= a; i++){
		dp[i-b] = dp[i-b-1] + 1;
		while(sz(dq) and dq.front() + div[dq.front()] <= i - b)
			dq.pop_front();
		if(sz(dq))
			dp[i - b] = dp[dq.front()] + 1;
		if(~div[i - b])
			dq.push_back(i - b);
	}
	cout << dp[a - b] << '\n';
	return 0;
}