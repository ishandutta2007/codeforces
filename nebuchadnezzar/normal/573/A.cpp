#include "bits/stdc++.h"
#define puba push_back
#define mapa make_pair
#define ff first
#define ss second
#define bend(_x) (_x).begin(), (_x).end()
#define szof(_x) ((int) (_x).size())

using namespace std;
typedef long long ll;
typedef double dbl;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

int n;

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {    
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

    cin >> n;

    //ll t = 1;
    vector <ll> v;

    for (int i = 0; i < n; ++i) {
        ll num;
        cin >> num;
        v.puba(num);
    }

    for (int i = 0; i < n - 1; ++i) {
        ll t = v[i] * v[i + 1] / gcd(v[i], v[i + 1]);
        int rest = t / v[i];
        while (rest % 2 == 0) {
            rest /= 2;
        }
        while (rest % 3 == 0) {
            rest /= 3;
        }
        if (rest != 1) {
            cout << "No\n";
            return 0;
        }
        rest = t / v[i + 1];
        while (rest % 2 == 0) {
            rest /= 2;
        }
        while (rest % 3 == 0) {
            rest /= 3;
        }
        if (rest != 1) {
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";

    return 0;
}