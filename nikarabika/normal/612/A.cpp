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
#define smin(x, y) (x) = min((x), (y))
#define smax(x, y) (x) = max((x), (y))

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, p, q;
	string s;
	cin >> n >> p >> q;
	cin >> s;
	for(int i = 0; i <= n; i += p)
		if((n - i) % q == 0){
			cout << i / p + (n - i) / q << endl;
			for(int ii = 0; ii < i; ii += p)
				cout << s.substr(ii, p) << endl;
			for(int ii = i; ii < n; ii += q)
				cout << s.substr(ii, q) << endl;
			return 0;
		}
	cout << -1 << endl;
	return 0;
}