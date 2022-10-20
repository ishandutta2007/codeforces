#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n;
int a[N], pos[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        int u;
        cin >> u;
        pos[u] = i;
    }
    int maxPos = 0;
    int res = 0;
    for (int i = 1; i <= n; i++) {
        int id = a[i];
        if (pos[id] < maxPos) res++;
        maxPos = max(maxPos, pos[id]);
    }
    cout << res << endl;
    return 0;
}