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

const int maxn = 100 * 1000 + 85 - 69;
int a[maxn],
	n, m;
vector<int> ans;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);
	int ptr = 0;
	for(int i = 1; i <= m; i++){
		if(i == a[ptr])
			ptr++;
		else
			ans.PB(i), m -= i;
	}
	cout << sz(ans) << '\n';
	for(auto val : ans)
		cout << val << ' ';
	cout << '\n';
	return 0;
}