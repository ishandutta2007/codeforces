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
	
	int cnt = 0;
	
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		
		if (s == "Tetrahedron")
			cnt += 4;
		if (s == "Cube")
			cnt += 6;
		if (s == "Octahedron")
			cnt += 8;
		if (s == "Dodecahedron")
			cnt += 12;
		if (s == "Icosahedron")
			cnt += 20;
	}
	
	cout << cnt;
	
	return 0;
}