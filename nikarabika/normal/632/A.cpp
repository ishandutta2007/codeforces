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
	LL p;
	string s[50];
	cin >> n >> p;
	for(int i = 0; i < n; i++)
		cin >> s[i];
	LL app = 0;
	for(int i = n - 1; i >= 0; i--){
		app *= 2;
		if(s[i] != "half")
			app++;
	}
	LL ans = 0;
	for(int i = 0; i < n; i++){
		ans += app * p / 2;
		app /= 2;
	}
	cout << ans << endl;
	return 0;
}