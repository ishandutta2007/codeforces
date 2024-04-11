#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n;
int a[N], b[N];
multiset<int> s;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
        b[i] = a[i];
    }
    sort(a + 1, a + n + 1);
    sort(b + 1, b + n + 1);
    int m = unique(b + 1, b + n + 1) - b - 1;
    for (int i = 1; i <= n; i++) {
        a[i] = lower_bound(b + 1, b + m + 1, a[i]) - b;
        s.insert(a[i]);
    }
    int res = 0;
    for (int i = n; i; i--) {
        s.erase(a[i]);
        if (s.empty()) {
            break;
        }
        auto it = s.lower_bound(a[i]);
        if (it == s.begin()) {
            break;
        }
        it--;
        res++;
        s.erase(it);
    }
    cout << res << endl;
    return 0;
}