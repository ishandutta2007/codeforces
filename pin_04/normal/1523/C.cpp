#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;
const int N = 1e5 + 5; 

int a[N];
int n;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> a[i];
	
		vector <int> s;
		for (int i = 1; i <= n; i++) {
			if (a[i] > 1) {
				while (s.back() + 1 != a[i]) 
					s.pop_back();
				s.pop_back();
			}
			s.push_back(a[i]);
			cout << s[0];
			for (int i = 1; i < (int) s.size(); i++) 
				cout << '.' << s[i];
			cout << "\n";
		}
	}
	return 0;
}