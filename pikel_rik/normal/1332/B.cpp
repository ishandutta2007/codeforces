#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        vector<int> ced(1001), primes = {2,3,5,7,11,13,17,19,23,29,31};

        for (int j = 0; j < 11; j++) {
            for (int i = primes[j] * primes[j]; i <= 1000; i+=primes[j]) {
                if (ced[i] == 0)
                    ced[i] = j+1;
            }
        }

        vector<int> count(12);
        for (int i = 0; i < n; i++) {
            count[ced[a[i]]] += 1;
        }

        vector<int> c;
        for (int i = 1; i <= 11; i++) {
            if (count[i] == 0)
                c.push_back(i);
        }

        if (n > 11) {
            int k = 0;
            cout << 11 << "\n";
            for (int i = 0; i < n; i++) {
                if (count[ced[a[i]]] > 1 and k < c.size()) {
                    cout << c[k++] << " ";
                    count[ced[a[i]]] -= 1;
                }
                else
                    cout << ced[a[i]] << " ";
            }
            cout << "\n";
        }
        else {
            cout << n << "\n";
            for (int i = 0; i < n; i++) {
                cout << i+1 << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}