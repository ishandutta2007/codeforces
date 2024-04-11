#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

long long n, m, t, sum = 0;
//
long long combinations(long long n, long long k) {
        if (n < k) return 0;
        long long ans = 1;
        long long st = 2;
        for (int i = k + 1; i <= n; i++) {
                while ((ans % st == 0) && (st <= n - k)) {
                        ans /= st;
                        st++;
                }
                ans *= i;
        }
        while ((ans % st == 0) && (st <= n - k)) {
                ans /= st;
                st++;
        }
        return ans;
}
//
int main() {
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        //
        cin >> n >> m >> t;
        for (long long g = 1; g <= t - 4; g++) {
                if (g <= m) {
                        sum += combinations(m, g)*combinations(n, t-g);
                }
        }
        cout << sum << endl;
        //
        return 0;
}