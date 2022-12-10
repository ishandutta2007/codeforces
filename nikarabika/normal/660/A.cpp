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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	int a[10000];
	vector<int> ans;
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	ans.PB(a[0]);
	for(int i = 1; i < n; i++){
		if(__gcd(a[i - 1], a[i]) != 1)
			ans.PB(1);
		ans.PB(a[i]);
	}
	cout << sz(ans) - n << '\n';
	for(auto val : ans)
		cout << val << ' ';
	cout << '\n';
	return 0;
}