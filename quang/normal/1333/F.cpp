#include <bits/stdc++.h>

using namespace std;

const int N = 500010;

int n;
int p[N];
int val[N];
set<pair<int, int>> s;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 2; i <= n; i++) {
        if (!p[i]) {
            for (int j = i; j <= n; j += i) {
                if (!p[j]) p[j] = i;
            }
        }
    }
    p[1] = 1;
    for (int i = 1; i <= n; i++) {
        val[i] = i / p[i];
    }
    sort(val + 1, val + n + 1);
    for (int i = 2; i <= n; i++) cout << val[i] << ' ';
        cout << endl;
    return 0;
}