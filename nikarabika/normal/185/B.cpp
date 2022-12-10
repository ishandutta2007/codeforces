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
	double s, a, b, c;
	cin >> s
		>> a >> b >> c;
	double su = a + b + c;
	if(int(su + .5) == 0){
		cout << s << ' ' << 0 <<' ' << 0 << endl;
		return 0;
	}
	cout.precision(10);
	cout << fixed << s * (a / su) << ' ' << s * b / su << ' ' << s * c / su << endl;
	return 0;
}