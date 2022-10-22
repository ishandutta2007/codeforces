#include <bits/stdc++.h>
#define INF 2147483647
#define LLINF LLONG_MAX
#define PI 3.1415926535
#define MOD 1000000007
#define MOD2 998244353
#define SP << " "
#define EL << "\n"
#define FL << flush
#define sqr(x) ((x)*(x))
#define pb push_back
using namespace std;
template <class T1, class T2> ostream& operator << (ostream& out, pair<T1,T2> p);
template <template <class...> class _TContainer, class... _T> ostream& operator << (ostream& out, _TContainer<_T...>& _Container);

vector<int> v[2];

int main() {
	int n,k;
	cin >> n >> k;
	
	string s;
	cin >> s;
	
	for (int i = 0; i < n; i++) {
		if (s[i] == '0')
			v[0].pb(i);
		else
			v[1].pb(i);
	}	
	
	bool isEvitable = 0;
	
	if (v[0].empty() || v[1].empty()) {
		cout << "tokitsukaze";
		return 0;
	}
		
	if (v[0].back() - v[0].front() < k || v[1].back() - v[1].front() < k) {
		cout << "tokitsukaze";
		return 0;
	}
	
	for (int l = 0, r = k-1; r < n; l++, r++) {
		for (int color = 0; color <= 1; color++) {
			int rp = v[1-color].back();
			if (l <= rp && rp <= r) rp = *--lower_bound(v[1-color].begin(),v[1-color].end(),l);
			int lp = v[1-color].front();
			if (l <= lp && lp <= r) lp = *upper_bound(v[1-color].begin(),v[1-color].end(),r);
			if (rp - lp >= k)
				isEvitable = 1;
		}
	}
	
	if (isEvitable)
		cout << "once again";
	else
		cout << "quailty";
	
	return 0;
}
 
/*
  _____                                               _               _       _                   _ _ 
 |  __ \                                             (_)             (_)     | |                 | | |
 | |__) | __ ___   __ _ _ __ __ _ _ __ ___  _ __ ___  _ _ __   __ _   _ ___  | |__   __ _ _ __ __| | |
 |  ___/ '__/ _ \ / _` | '__/ _` | '_ ` _ \| '_ ` _ \| | '_ \ / _` | | / __| | '_ \ / _` | '__/ _` | |
 | |   | | | (_) | (_| | | | (_| | | | | | | | | | | | | | | | (_| | | \__ \ | | | | (_| | | | (_| |_|
 |_|   |_|  \___/ \__, |_|  \__,_|_| |_| |_|_| |_| |_|_|_| |_|\__, | |_|___/ |_| |_|\__,_|_|  \__,_(_)
                   __/ |                                       __/ |                                  
                  |___/                                       |___/                                                                                 
*/

static auto _batch_ios = [](){
	ios::sync_with_stdio(false);
	cin.tie(0);
	return 42;
}();
template <class T1, class T2>
ostream& operator << (ostream& out, pair<T1,T2> p) {
	return out << '(' << p.first << ',' << p.second << ')';
}
template <template <class...> class _TContainer, class... _T>
ostream& operator << (ostream& out, _TContainer<_T...>& _Container) {	
    out << '[';
    bool first = 1;
    for(auto x : _Container) {
    	if (!first) out << ',';
    	out << x;
    	first = 0;
    }
    out << ']';
    return out;
}