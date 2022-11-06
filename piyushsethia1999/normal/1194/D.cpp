#include <bits/stdc++.h>
#define pb emplace_back
#define fi first
#define se second
using namespace std;
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int l) { uniform_int_distribution<int> uid(0, l - 1); return uid(rang); }

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10); srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int k; cin >> k;
        if (k % 3 != 0) {
            int an = n % 3;
            if (an) {
                cout << "Alice\n";
            } else 
                cout << "Bob\n";
        } else {
            n %= (k + 1);
            if (n == k) {
                cout << "Alice\n";
            } else if(n % 3) {
                cout << "Alice\n";
            } else {
                cout << "Bob\n";
            }
        }

    }
}