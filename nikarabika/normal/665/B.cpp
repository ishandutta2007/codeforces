//sobskdrbhvk
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
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

const int maxn = 85 + 85 - 69;
int pos[maxn];
int n, m, k;
vector<int> sto;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	for(int i = 0; i < k; i++){
		int x;
		cin >> x, x--;
		sto.PB(x);
	}
	LL ans = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			int x;
			cin >> x, x--;
			int id = find(all(sto), x) - sto.begin();
			ans += id + 1;
			sto.erase(sto.begin() + id);
			sto.insert(sto.begin(), x);
		}
	}
	cout << ans << endl;
	return 0;
}