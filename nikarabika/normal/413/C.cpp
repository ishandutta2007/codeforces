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

const int maxn = 85 + 85 - 69;
LL a[maxn],
   sum, n, m;
vector<LL> vec;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		cin >> a[i], sum += a[i];
	for(int i = 0; i < m; i++){
		int fi;
		cin >> fi, fi--;
		sum -= a[fi];
		vec.PB(a[fi]);
	}
	sort(all(vec), greater<int>());
	for(auto val : vec)
		sum += max(sum, val);
	cout << sum << endl;
	return 0;
}