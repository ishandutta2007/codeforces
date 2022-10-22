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

template <class T1,class T2>
ostream& operator << (ostream& out, pair<T1,T2> p) {
	cout << "(" << p.first << "," << p.second << ")";
	return out;
}

static auto _batch_ios = [](){
	ios::sync_with_stdio(false);
	cin.tie(0);
	return 42;
}();

/******************************************/

int main() {
	int n;
	cin >> n;
	
	string s = "";
	
	for (int i = 0; i < n; i++) {
		if (i % 2)
			s += "I love ";
		else
			s += "I hate ";
			
		if (i == n-1)
			s += "it";
		else
			s += "that ";
	}
	
	cout << s;
	
	return 0;
}