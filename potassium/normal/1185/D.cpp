#include <bits/stdc++.h>
#define INF 2147483647
#define LLINF LLONG_MAX
#define PI 3.1415926535
#define MOD 1000000007
#define SP << " "
#define EL << "\n"
#define initrand(x) mt19937 x(chrono::steady_clock::now().time_since_epoch().count());
#define initrand64(x) mt19937_64 x(chrono::steady_clock::now().time_since_epoch().count());
using namespace std;

template <class T1, class T2>
ostream& operator << (ostream& os, pair<T1,T2> p) {
	os << "(" << p.first << "," << p.second << ")";
	return os;
}

int n;
int a[200009],b[200009];

void find(int x) {
	for (int i = 0; i < n; i++)
		if (b[i] == x) {
			cout << i+1;
			break;
		}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		b[i] = a[i];
	}
		
	sort(a,a+n);
	
	map<int,int> m;
	
	for (int i = 0; i < n-1; i++)
		m[a[i+1]-a[i]]++;
		
	if (m.size() == 1) {
		find(a[0]);
		return 0;
	}
		
	if (m.size() > 3) {
		cout << -1;
		return 0;
	}
		
	if (m.size() == 2 || m.size() == 3) {					
		if (m.size() == 2 && m[a[1]-a[0]] == 1) {
			find(a[0]);
			return 0;
		}
			
		if (m.size() == 2 && m[a[n-1]-a[n-2]] == 1) {
			find(a[n-1]);
			return 0;
		}
			
		for (int i = 1; i < n-1; i++) {
			int diff = a[i+1] - a[i-1];
			int cnt = m[diff] + 1;
			
			if (a[i+1] - a[i] == diff)
				cnt--;
				
			if (a[i] - a[i-1] == diff)
				cnt--;
			
			if (cnt == n-2) {
				find(a[i]);
				return 0;
			}
		}
		
		cout << -1;
		return 0;
	}
					
	return 0;
}