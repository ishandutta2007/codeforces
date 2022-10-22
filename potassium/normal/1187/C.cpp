#include <bits/stdc++.h>
#define INF 2147483647
#define LLINF LLONG_MAX
#define PI 3.1415926535
#define MOD 1000000007
#define SP << " "
#define EL << "\n"
#define sqr(x) ((x)*(x))
//mt19937 x(chrono::steady_clock::now().time_since_epoch().count());
//mt19937_64 x(chrono::steady_clock::now().time_since_epoch().count());
using namespace std;
template <class T1, class T2> ostream& operator << (ostream& out, pair<T1,T2> p);
template <template <class...> class _TContainer, class... _T> ostream& operator << (ostream& out, _TContainer<_T...>& _Container);
 
int a[1001];
int ps[1001];
 
struct range_union{
	vector<pair<int,int> > v;
	vector<pair<int,int> > range;
	
	inline void insert(int l, int r) {
		v.push_back({l,r});
	}
	
	inline void merge() {
		sort(v.begin(),v.end());
		
		for (auto i : v) {
			if (range.empty() || i.first - range.rbegin()->second > 0)
				range.push_back(i);
			else
				range.rbegin()->second = max(range.rbegin()->second,i.second);
		}
	}
};
 
int main() {
	int n,m;
	cin >> n >> m;
	
	vector<pair<int,int> > v;
	v.clear();
	
	while (m--) {
		int t,l,r;
		cin >> t >> l >> r;
		
		if (t == 0)
			v.push_back({l,r});
		else
			for (int i = l+1; i <= r; i++)
				a[i] = 1;
	}
	
	bool isPossible = 1;
	
	for (int i = 1; i <= n; i++)
		ps[i] = ps[i-1] + a[i];
	
	for (auto i : v) {
		if (ps[i.second]-ps[i.first] == i.second-i.first) {
			isPossible = 0;
			break;
		}
	}
		
	if (isPossible) {
		cout << "Yes\n";
		int cur = 10000;
		
		for (int i = 1; i <= n; i++) {
			if (a[i] == 1)
				cout << ++++cur SP;
			else
				cout << ----cur SP;
		}
	} else {
		cout << "No\n";
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