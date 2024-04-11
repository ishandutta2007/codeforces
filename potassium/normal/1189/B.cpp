#include <bits/stdc++.h>
#define INF 2147483647
#define LLINF LLONG_MAX
#define PI 3.1415926535
#define MOD 1000000007
#define SP << " "
#define EL << "\n"
#define FL << flush
#define sqr(x) ((x)*(x))
#define pb push_back
//mt19937 x(chrono::steady_clock::now().time_since_epoch().count());
//mt19937_64 x(chrono::steady_clock::now().time_since_epoch().count());
using namespace std;
template <class T1, class T2> ostream& operator << (ostream& out, pair<T1,T2> p);
template <template <class...> class _TContainer, class... _T> ostream& operator << (ostream& out, _TContainer<_T...>& _Container);

int main() {
	int n;
	cin >> n;
	
	vector<int> v;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.pb(x);
	}
	
	sort(v.begin(),v.end());
	
	vector<int> ans;
	ans.resize(n+10);
	
	int lptr = 0, rptr = n-1, ptr = 0;
	
	while (ptr < n) {
		ans[lptr++] = v[ptr++];
		if (ptr == n)
			break;
		ans[rptr--] = v[ptr++];
	}
	
	bool isPossible = 1;
	if (ans[0] >= ans[1] + ans[n-1])
		isPossible = 0;
	if (ans[n-1] >= ans[0] + ans[n-2])
		isPossible = 0;
	
	for (int i = 1; i <= n-2; i++)
		if (ans[i] >= ans[i-1] + ans[i+1])
			isPossible = 0;
			
	if (isPossible) {
		cout << "YES\n";
		for (int i = 0; i < n; i++)
			cout << ans[i] SP;
	} else {
		cout << "NO";
	}
	
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
static auto _batch_ios = [](){
	ios::sync_with_stdio(false);
	cin.tie(0);
	return 42;
}();