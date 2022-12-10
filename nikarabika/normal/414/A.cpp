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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	if(k < n / 2){
		cout << -1 << endl;
		return 0;
	}
	if(n == 1){
		if(k == 0)
			cout << 1 << endl;
		else
			cout << -1 << endl;
		return 0;
	}
	k -= n / 2 - 1;
	int div = 1000000000 / k;
	cout << div * k << ' ' << (div - 1) * k << ' ';
	for(int i = 2; i < n; i++)
		cout << i << ' ';
	cout << '\n';
	return 0;
}