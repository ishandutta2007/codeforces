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
	return out << "(" << p.first << "," << p.second << ")";
}
template <class T>
ostream& operator << (ostream& out, vector<T> v) {
	out << "[";
	for (auto it = v.begin(); it < v.end(); it++) {
		if (it != v.begin())
			out << ",";
		out << *it;
	}
	out << "]";
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
	
	int cnt[6] = {0,0,0,0,0,0};
	
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		
		int num[6] = {4,8,15,16,23,42};
		int xnum;
		for (int i = 0; i < 6; i++)
			if (x == num[i])
				xnum = i;
				
		if (xnum == 0)
			cnt[0]++;
		else if (cnt[xnum] < cnt[xnum-1])
			cnt[xnum]++;
	}
	
	cout << n-6*cnt[5];
	
	return 0;
}