#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define sz(x) (int) x.size()

const int INF = 1e9 + 1;
const ll LINF = 1e18 + 1;

map<int, int> q;

int get(ll x) {
    int res = 0;
    for (int i = 0; i < 20; i++) {
        if ((x % 10) % 2 != 0) {
            res |= (1 << i);
        }
        x /= 10;
    }
    
    return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    
    int t;
    cin >> t;
    
    for (int i = 0; i < t; i++) {
        char c;
        cin >> c;
        
        if (c == '+') {
            ll a;
            cin >> a;
            q[get(a)]++;
        } else if (c == '-') {
            ll a;
            cin >> a;
            q[get(a)]--;
        } else {
            ll s;
            cin >> s;
            cout << q[get(s)] << "\n";
        }
    }
	
	return 0;
}