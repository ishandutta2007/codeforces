#include <iostream>
#include <map>

using namespace std;

typedef long long ll;

map<pair<ll,int>,pair<ll,ll>> dd;

pair<ll,ll> calc(ll x, int c) {
	//cout << "lol " << x << " " << c << "\n";
	//if (x == 0) return {0,0};
	if (x < 10) return {max(x,(ll)c),1LL};
	if (dd.count({x,c})) return dd[{x,c}];
	ll u = 0;
	ll g = 0;
	string s = to_string(x);
	int f = s[0]-'0';
	s = s.substr(1);
	auto r = calc(stoll(s),max(c,f));
	auto w = calc(x-r.first,c);
	w.first += r.first;
	w.second += r.second;
	dd[{x,c}] = w;
	//cout << x << " " << c << " " << w.first << " " << w.second << "\n";
	return w;
}

int main() {
	ll n;
	cin >> n;
	if (n == 0) {
		cout << "0\n";
		return 0;
	}
	auto r = calc(n,0);
	cout << r.second << "\n";
}