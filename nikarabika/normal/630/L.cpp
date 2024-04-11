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
	string s, t;
	cin >> s;
	LL n = 0;
	t = "     ";
	t[0] = s[0], t[1] = s[2], t[2] = s[4], t[3] = s[3], t[4] = s[1];
	for(int i = 0; i < 5; i++)
		n = n * 10 + t[i] - '0';
	cerr << n << endl;
	n = (((((((n * n) % 100000) * n) % 100000) * n) % 100000) * n) % 100000;
	stringstream ss;
	ss << n;
	for(int i = 0; i < 5 - sz(ss.str()); i++)
		cout << 0;
	cout << n << endl;
	return 0;
}