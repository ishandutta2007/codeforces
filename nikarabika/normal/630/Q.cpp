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
	LD MPI = atan(1) * 4;
	LD l3, l4, l5;
	cin >> l3 >> l4 >> l5;
	LD ans3, ans4, ans5;
	ans3 = l3 * l3 * l3 / (6 * sqrt(2));
	LD d4 = l4 / sqrt(2);
	LD h4 = sqrt(l4 * l4 - d4 * d4);
	ans4 = l4 * l4 * h4 / 3;
	LD d5 = l5 / sqrt(2 - 2 * cos(72.0 / 180 * MPI));
	LD h5 = sqrt(l5 * l5 - d5 * d5);
	ans5 = l5 * l5 / 4 * sqrt(5 * (5 + 2 * sqrt(5))) * h5 / 3;
	cout.precision(18);
	cout << ans3 + ans4 + ans5 << endl;
	return 0;
}