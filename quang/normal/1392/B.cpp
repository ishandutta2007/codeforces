#include <bits/stdc++.h>

using namespace std;

const int N = 200010;

int n;
long long k;
int a[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc;
    cin >> tc;
    while (tc--) {
        cin >> n >> k;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        k--;
        int maxVal = *max_element(a + 1, a + n + 1);
        for (int i = 1; i <= n; i++) {
            a[i] = maxVal - a[i];
        }
        if (k % 2 == 1) {
            int maxVal = *max_element(a + 1, a + n + 1);
            for (int i = 1; i <= n; i++) {
                a[i] = maxVal - a[i];
            }
        }
        for (int i = 1; i <= n; i++) cout << a[i] << ' ';
            cout << '\n';
    }   
    return 0;
}