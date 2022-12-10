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

const int maxn = 1e5;
vector<int> vec[maxn];
int n, m, k, ans;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		vec[x-1].PB(i);
	}
	for(int i = 0; i < m; i++){
		int ptr = 0;
		for(int j = 0; j < sz(vec[i]); j++){
			int init = vec[i][j];
			while(ptr < sz(vec[i]) and vec[i][ptr] - init - (ptr - j) <= k) ptr++;
			smax(ans, ptr - j);
		}
	}
	cout << ans << endl;
	return 0;
}