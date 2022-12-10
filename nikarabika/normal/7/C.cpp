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

pll find_ans(LL a, LL b, LL c){
	if(b == 0)
		return MP(c / a, 0);
	pll an = find_ans(b, a % b, c);
	return MP(an.R, an.L - an.R * LL(a / b));
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	LL a, b, c;
	cin >> a >> b >> c;
	c = -c;
	if(abs(c) % __gcd(abs(a), abs(b)) != 0){
		cout << -1 << endl;
		return 0;
	}
	pll an = find_ans(abs(a), abs(b), c);
	if(a < 0)
		cout << -an.L << ' ';
	else
		cout << an.L << ' ';
	if(b < 0)
		cout << -an.R << endl;
	else
		cout << an.R << endl;
	return 0;
}