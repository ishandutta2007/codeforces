#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define Test(tt) cout << "Case #" << tt << ": "

using namespace std;

const int MAXVAL = (int)2e5;


int main() {
#ifdef HOME
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
    int i, n;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

   	cin >> n;

   	vector<vector<int>> expo(MAXVAL + 1);

   	for(i = 0; i < n; i++) {
   		int x;
   		cin >> x;

   		int d = 2;
   		while(d * d <= x) {
   			int e = 0;
   			while(x % d == 0) {
   				x /= d;
   				e++;
   			}
   			if(e > 0) {
   				expo[d].push_back(e);
   			}
   			d++;
   		}
   		if(x > 1) {
   			expo[x].push_back(1);
   		}
   	}

   	ll ans = 1;
   	for(i = 1; i <= MAXVAL; i++) {
   		sort(expo[i].begin(), expo[i].end());
   		if((int)expo[i].size() > n - 2) {
   			int e = expo[i][0];
   			if((int)expo[i].size() == n) {
   				e = expo[i][1];
   			}
   			while(e--) {
   				ans = 1LL * ans * i;
   			}
   		}
   	}
   	cout << ans << "\n";

    return 0;
}