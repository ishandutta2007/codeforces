#include <cstring>
#include <iostream>

using namespace std;
const int N = 2e5;

int a[N], look[N], negative;

void update(int x, int delta) {
    if (look[x] >= 0 && look[x] + delta < 0)
        negative++;
    if (look[x] < 0 && look[x] + delta >= 0)
        negative--;
    look[x] += delta;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n{};
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        look[a[i]]++;
    int cnt{};
    for (int i = 1; i <= n; i++)
        cnt += look[i] % 2;
    if (cnt > 1 || (cnt == 1 && n % 2 == 0)) {
        cout << "0\n";
        return 0;
    }
    for (int l = 1, r = n; ; l++, r--) {
        if (l > r) {
            cout << 1LL * n * (n + 1) / 2 << "\n";
            return 0;
        }
        if (a[l] == a[r])
            continue;
        long long ans{};
        negative = 0;
        memset(look, 0, sizeof(look));
        for (int i = (n + 1) / 2, j = n / 2 + 1; l <= i; i--, j++) {
            update(a[i], +1);
            update(a[j], -1);
        }
        for (int i = (n + 1) / 2, j = n / 2 + 1; l < i; i--, j++) {
            if (a[i] != a[j])
                break;
            update(a[i], -1);
            update(a[j], +1);
            if (negative == 0)
                ans += 2 * l;
        }
        negative = 0;
        memset(look, 0, sizeof(look));
        for (int i = l; i <= r; i++)
            update(a[i], (i <= (n + 1) / 2 ? +1 : -1));
        for (int i = (n + 1) / 2 + 1; i <= r + 1; i++) {
            if (negative == 0)
                ans += l;
            update(a[i], +2);
        }
        negative = 0;
        memset(look, 0, sizeof(look));
        for (int i = l; i <= r; i++)
            update(a[i], (i >= n / 2 + 1 ? +1 : -1));
        for (int i = n / 2; i >= l - 1; i--) {
            if (negative == 0) {
                ans += l;
                if (i == l - 1)
                    ans--;
            }
            update(a[i], +2);
        }
        ans += l - 1;
        cout << ans << "\n";
        break;
    }
    return 0;
}