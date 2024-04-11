#include <bits/stdc++.h>

using namespace std;
typedef long long int li;
typedef pair<int,int> pii;
typedef pair<li,li> pll;
#define mp make_pair
#define pb push_back

long long n, k, m, t, a, b, c, d, e, f, x, y;
set<long long> s;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while(t--){
		cin >> n;
		s.clear();
		for (int i=0; i<n; i++){
			cin >> a;
			a += n*1e9;
			a += i;
			a %= n;
			s.insert(a);
		}
		if (s.size() == n){
			cout << "YES\n";
		}
		else cout << "NO\n";
	}
}