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
	out << "(" << p.first << "," << p.second << ")";
	return out;
}

template <class T>
ostream& operator << (ostream& out, vector<T> v) {
	out << "[";
	for (int i = 0; i < v.size(); i++) {
		out << v[i];
		if (i != v.size()-1)
			out << ",";
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
	
	unordered_map<int,vector<int> > l,r;
	l.reserve(100007);
	r.reserve(100007);
	
	vector<int> zero;
	zero.reserve(100007);
	
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		
		int low = 0;
		int val = 0;
		
		for (int j = 0; j < s.length(); j++) {
			if (s[j] == '(')
				val++;
			else
				val--;
			low = min(low,val);
		}
		
		if (low == 0 && val == 0)
			zero.push_back(i);
		else {
			if (low == 0)
				l[val].push_back(i);
			if (val <= 0 && val <= low)
				r[val].push_back(i);
		}
	}
		
	int ans = zero.size() / 2;
		
	for (auto i : l) {
		unordered_map<int,vector<int> >::iterator it = r.find(-i.first);
		if (it != r.end())
			ans += min(i.second.size(),it->second.size());
	}
	
	cout << ans;
	
	return 0;
}