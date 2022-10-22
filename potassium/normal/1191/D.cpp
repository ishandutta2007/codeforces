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

vector<int> v;
 
int main() {
	int n;
	cin >> n;
	
	v.resize(n);
	
	for (int i = 0; i < n; i++)
		cin >> v[i];
		
	sort(v.begin(),v.end());
	
	bool isValid = 1;
	
	int cnt2 = 0;
	
	for (int i = 0; i < n-1; i++) {
		if (v[i] == v[i+1]) {
			cnt2++;
			if (v[i] == 0)
				isValid = 0;
			if (v[i-1] + 1 == v[i])
				isValid = 0;
		}
	}
	
	if (cnt2 > 1)
		isValid = 0;
	
	if (isValid) {
		int sum = 0;
		for (int i = 0; i < n; i++)
			sum += v[i] & 1;
		if (n % 4 == 3 || n % 4 == 2)
			sum--;
		if (sum % 2 == 0) 
			cout << "cslnb";
		else
			cout << "sjfnb";
	} else
		cout << "cslnb";
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