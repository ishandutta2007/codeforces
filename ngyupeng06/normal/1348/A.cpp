#include <bits/stdc++.h>

using namespace std;
typedef long long int li;
typedef pair<int,int> pii;
typedef pair<li,li> pll;
#define mp make_pair
#define pb push_back

long long n, m, t, a, b, c, d, e, f, x, y;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while(t--){
		cin >> n;
		long long ans = 0;
		long long cur = 1;
		for (int i=1; i<=n; i++){
			cur*=2;
			if (i<n/2 || i == n){
				ans += cur;
			}
			else ans -= cur;
		}
		cout << ans << "\n";
	}
}