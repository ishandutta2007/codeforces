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
typedef long long ll;
using namespace std;
template <class T1, class T2> ostream& operator << (ostream& out, pair<T1,T2> p);
template <template <class...> class _TContainer, class... _T> ostream& operator << (ostream& out, _TContainer<_T...>& _Container);

map<int,int> m;

int main() {
	m.insert({1,1});
	m.insert({3,1});
	m.insert({7,1});
	m.insert({15,5});
	m.insert({31,1});
	m.insert({63,21});
	m.insert({127,1});
	m.insert({255,85});
	m.insert({511,73});
	m.insert({1023,341});
	m.insert({2047,89});
	m.insert({4095,1365});
	m.insert({8191,1});
	m.insert({16383,5461});
	m.insert({32767,4681});
	m.insert({65535,21845});
	m.insert({131071,1});
	m.insert({262143,87381});
	m.insert({524287,1});
	m.insert({1048575,349525});
	m.insert({2097151,299593});
	m.insert({4194303,1398101});
	m.insert({8388607,178481});
	m.insert({16777215,5592405});
	m.insert({33554431,1082401});
	
	int q;
	cin >> q;
	while(q--) {
		int x;
		cin >> x;
		auto it = m.find(x);
		if (it != m.end())
			cout << it->second EL;
		else
			cout << (1 << __lg(x)+1)-1 EL;
	}
	
	return 0;
}

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