#include <bits/stdc++.h>

using namespace std;
typedef long long int li;
typedef pair<int,int> pii;
typedef pair<li,li> pll;
#define mp make_pair
#define pb push_back

long long n, m, t;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--){
		cin >> n;
		long long cur = 2, ans;
		for (int i=1; i < 60; i++){
			cur *= 2;
			if (n <= cur - 1){
				ans = i;
				break;
			}
		}
		if (n == 2) cout << "1\n0\n";
		else if (n==3) cout << "1\n1\n";
		else {
			cout << ans << "\n";
			long long cur2 = cur / 2;
			long long cc = 1;
			for (int i=1; i<=ans-2; i++){
				cout << cc << " ";
				cc*=2;
			}
			if (n >= cur2 - 1 + cur2/2){
				cout << cc << " " << n - cur2 - cur2/2 + 1 << "\n";
			}
			else {
				long long xx = n - cc*2 + 1;
				if (xx % 2 == 0){
					cout << (xx)/2 - cc << " " << 0 << "\n";
				}
				else {
					cout << (xx)/2 - cc << " " << 1 << "\n";
				}
			}
		}
	}
}