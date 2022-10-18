#ifdef ONPC
    #define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
#define char unsigned char

using namespace std;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

typedef long long ll;
typedef long double ld;

int solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for (int &i : a) {
        cin >> i;
    }
    for (int &i : b) {
        cin  >> i;
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    ll suma = 0;
    ll sumb = 0;
    for (int i = n / 4; i < n; i++) {
        suma += a[i];
        sumb += b[i];
    }
    for (int i = n - 2; i >= 0; i--) {
        b[i] += b[i + 1];
    }
    int m = n;
    while (suma < sumb) {
        m++;
        suma += 100;
        if (m % 4 == 0) {
            if (m / 4 < n) {
                suma -= a[m / 4 - 1];
            } else {
                suma -= 100;
            }
        }
        sumb = b[max(0, n - (m - m / 4))];
        
    }
    cout << m - n << '\n';
    return 0;
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int TET = 1e9;
    cin >> TET;
    for (int i = 1; i <= TET; i++) {
        if (solve()) {
            break;
        }
        #ifdef ONPC
            cout << "__________________________" << endl;
        #endif
    }
    #ifdef ONPC
        cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
    #endif
}