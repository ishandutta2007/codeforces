#include <iostream>

#define ll long long int

using namespace std;

int n;
ll a[100000];

ll syt(ll a, ll b) {
    if (a%b == 0) return b;
    else return syt(b, a%b);
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll t = a[0];
    for (int i = 1; i < n; i++) {
        t = syt(t, a[i]);
    }
    for (int i = 0; i < n; i++) {
        if (a[i] == t) {
            cout << t << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}