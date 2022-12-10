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

const int maxn = 2e6 + 85 - 69;
int ans[maxn], n;
LL sum;

void solve(int n, int st = 0){
	int id = 0;
	while((1 << (id + 1)) <= n) id++;
	if((1 << id) != n){
		int rem = n & ((1 << id) - 1);
		sum += 2LL * rem * (1 << id);
		for(int i = 0; i < rem; i++)
			ans[st + n - rem - i - 1] += 1 << id;
		solve(n - rem, st);
		solve(rem, st + n - rem);
		return;
	}
	sum += 1LL * (n - 1) * n;
	for(int i = 0; i < n; i++)
		ans[st + n - 1 - i] += i;
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n, n++;
	solve(n);
	cout << sum << '\n';
	for(int i = 0; i < n; i++)
		cout << ans[i] << ' ';
	cout << '\n';
	return 0;
}