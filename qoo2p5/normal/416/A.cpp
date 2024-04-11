#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = (int) 1e9 + 123;
const ll LINF = (ll) 1e18 + 123;
const ld EPS = (ld) 1e-7;
const int MOD = (int) 1e9 + 7;

#define sz(x) (int) (x).size()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define all(x) (x).begin(), (x).end()
#define lb(s, t, x) (int) (lower_bound(s, t, x) - s)
#define ub(s, t, x) (int) (upper_bound(s, t, x) - s)

template<typename A, typename B> bool mini(A &x, const B &y) {
    if (y < x) {
        x = y;
        return true;
    }
    return false;
}

template<typename A, typename B> bool maxi(A &x, const B &y) {
    if (y > x) {
        x = y;
        return true;
    }
    return false;
}

void run();

int main() {
#ifndef LOCAL
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#endif
    run();
    return 0;
}

// == BEGIN CODE == //

void run() {
    int left = -2000000000;
    int right = 2000000000;
    
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int x;
        cin >> x;
        char ans;
        cin >> ans;
        
        if (ans == 'N') {
            if (s == ">") {
                s = "<=";
            } else if (s == ">=") {
                s = "<";
            } else if (s == "<") {
                s = ">=";
            } else if (s == "<=") {
                s = ">";
            }
        }
        if (s == ">") {
            maxi(left, x + 1);
        } else if (s == ">=") {
            maxi(left, x);
        } else if (s == "<") {
            mini(right, x - 1);
        } else if (s == "<=") {
            mini(right, x);
        }
    }
    
    if (left <= right) {
        cout << left << "\n";
    } else {
        cout << "Impossible\n";
    }
}