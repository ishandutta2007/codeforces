#include <bits/stdc++.h>

using namespace std;

const int N = 1e6+1;

int v[N];

int main() {
    int n;
    cin >> n;
    int maxs = -1, ans = 0;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        v[a]++;
        if (v[a] > maxs) {
            maxs = v[a];
            ans = a;
        }
    }
    cout << ans;
    return 0;
}