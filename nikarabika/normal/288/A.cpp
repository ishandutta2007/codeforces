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
	if(k > n or (k == 1 and n > 1)){
		cout << -1 << endl;
		return 0;
	}
	if(k == 1){
		cout << 'a' << endl;
		return 0;
	}
	for(int i = 0; i < n - k + 2; i++)
		cout << char('a' + (i&1));
	for(int i = 2; i < k; i++)
		cout << char('a' + i);
	cout << '\n';
	return 0;
}