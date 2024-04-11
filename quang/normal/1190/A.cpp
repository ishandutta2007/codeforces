#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

long long n;
int m;
long long k;
long long a[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        cin >> a[i];
        a[i]--;
    }
    int res = 0;
    for (int l = 1, r = 1; l <= m; l = r) {
        res++;
        long long now = (a[l] - l + 1) / k;
        while (r <= m && (a[r] - l + 1) / k == now) r++;
    }
    cout << res << endl;
    return 0;
}