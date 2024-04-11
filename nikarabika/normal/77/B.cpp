//sobskdrbhvk
//remember the flying, the bird dies ):(
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef double LD;
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
	int t;
	cin >> t;
	cout.precision(15);
	for(int i = 0; i < t; i++){
		LD a, b;
		cin >> a >> b;
		if(a < .5){
			if(b < .5)
				cout << fixed << 1 << '\n';
			else
				cout << fixed << .5 << '\n';
			continue;
		}
		if(b < .5){
			cout << fixed << 1 << '\n';
			continue;
		}
		LD S = -b/a;
		S += (a + 4 * b) / (2*a*b) * (a / 4 + b) / 2;
		if(a / 4 > b)
			S -= (a / 4 - b) / (2*a*b) * (a - 4 * b) / 2;
		cout << fixed << S << '\n';
	}
	return 0;
}