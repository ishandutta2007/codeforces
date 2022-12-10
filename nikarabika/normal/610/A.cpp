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
	int n;
	cin >> n;
	if(n & 1){
		cout << 0 << endl;
		return 0;
	}
	if(n % 4 == 2){
		cout << n / 4 << endl;
		return 0;
	}
	cout << n / 4 - 1 << endl;
	return 0;
}