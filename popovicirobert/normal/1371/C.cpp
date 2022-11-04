#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define Test(tt) cout << "Case #" << tt << ": "

using namespace std;




int main() {
#ifdef HOME
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
    int t;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

   	cin >> t;
   	while(t--) {
   		ll a, b, n, m;
   		cin >> a >> b >> n >> m;

   		if(a + b < n + m) {
   			cout << "No\n";
   			continue;
   		}

   		if(min(a, b) >= m) {
   			cout << "Yes\n";
   		}
   		else {
   			cout << "No\n";
   		}
   	}


    return 0;
}