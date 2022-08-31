#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pi;

const int mod = 1e9 + 7;

int len (int x) {
    int c = 0;
    while (x) {
        x >>= 1;
        c += 1;
    }
    return c;
}

int main() {
    ios::sync_with_stdio(false);


    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vi a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        int time = 0;
        for (int i = 1; i < n; i++) {
            if (a[i] < a[i-1]) {
                time = max(time, len(a[i - 1] - a[i]));
                a[i] = a[i - 1];
            }
        }
        cout << time << "\n";
    }
    return 0;
}