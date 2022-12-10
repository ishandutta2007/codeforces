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

const int maxn = 1e5 + 10;
int ans[maxn],
	n;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	if(n & 2){
		cout << -1 << endl;
		return 0;
	}
	memset(ans, -1, sizeof ans);
	for(int i = 0; i < n and ans[i] == -1; i+=2){
		if(n - i - 1 == i){
			ans[i] = i;
			continue;
		}
		ans[i] = i + 1;
		ans[i + 1] = n - i - 1;
		ans[n - i - 1] = n - i - 2;
		ans[n - i - 2] = i;
	}
	for(int i = 0; i < n; i++)
		cout << ans[i] + 1 << ' ';
	cout << endl;
	return 0;
}