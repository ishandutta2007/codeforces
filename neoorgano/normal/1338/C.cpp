#include <bits/stdc++.h>
using namespace std;
#define int int64_t

int arr[3][4] = {
{0, 1, 2, 3},
{0, 2, 3, 1},
{0, 3, 1, 2}
};

main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        n--;
        int num = n / 3;
        if (num == 0) {
            cout << n + 1 << endl;
            continue;
        }
        int cnt = 0, k = 0;
        int cur = 1;
        while (k + cur <= num) {
            cnt++;
            k += cur;
            cur *= 4;
        }
        int res = 0;
        cnt *= 2;
        if (n % 3 == 0) {
            res += (1ll << cnt);
        } else if (n % 3 == 1) {
            res += (1ll << (cnt + 1));
        } else {
            res += (1ll << (cnt + 1));
            res += (1ll << cnt);
        }
        num -= k;
        res += num;
        for (int i = 0; i < cnt; i += 2) {
            res -= (num % 4) << i;
            res += arr[n % 3][num % 4] << i;
            num /= 4;
        }
        cout << res << endl;
    }
    return 0;
}