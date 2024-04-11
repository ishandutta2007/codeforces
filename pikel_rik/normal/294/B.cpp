#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

typedef unsigned long long ull;
typedef long long ll;

const int mod = 1e9 + 7;
const int inf = 2e9 + 5;

int n, total, a[100], b[100];

bool comp(int a, int b) {
    return a > b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    int ptr1 = 0, ptr2 = 0;

    for (int i = 0; i < n; i++) {
        int t, w; cin >> t >> w;
        if (t == 1) a[ptr1++] = w;
        else b[ptr2++] = w;
        total += w;
    }

    sort(a, a + n, comp);
    sort(b, b + n, comp);

    int best = inf;
    for (int v1 = 0; v1 <= ptr1; v1++) {
        int sum = 0;
        for (int i = 0; i < v1; i++)
            sum += a[i];

        for (int v2 = 0; v2 <= ptr2; v2++) {
            int sum1 = 0;
            for (int j = 0; j < v2; j++)
                sum1 += b[j];

            if (v1 + 2 * v2 >= total - sum - sum1)
                best = min(best, v1 + 2 * v2);
        }
    }

    cout << best << "\n";
    return 0;
}