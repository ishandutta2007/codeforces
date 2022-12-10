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
	string s;
	int x;
	cin >> s >> x;
	int h = 0, m = 0;
	for(int i = 0; i < 2; i++)
		h = h * 10 + s[i] - '0';
	for(int i = 3; i < 5; i++)
		m = m * 10 + s[i] - '0';
	m += x;
	h += m / 60;
	m %= 60;
	h %= 24;
	cout << (h < 10 ? "0" : "") << h << ':' << (m < 10 ? "0" : "") << m << endl;
	return 0;
}