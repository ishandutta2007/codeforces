//sobskdrbhvk
//remember...
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
#define smin(x, y) (x) = min((x), (y))
#define smax(x, y) (x) = max((x), (y))
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int h1, m1, h2, m2;
	char c;
	cin >> h1 >> c >> m1
		>> h2 >> c >> m2;
	int h3, m3,
		h4, m4;
	h3 = h1 + h2;
	m3 = m1 + m2;
	h3 += m3 / 60;
	m3 %= 60;
	h4 = h3 / 2;
	m4 = ((h3 & 1) * 60 + m3) / 2;
	cout << (h4 < 10 ? "0" : "") << h4 << ':' << (m4 < 10 ? "0" : "") << m4 << endl;
	return 0;
}