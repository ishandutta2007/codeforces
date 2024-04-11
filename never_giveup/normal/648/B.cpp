#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 2e3;

ll n, m, q[maxn];

int main(){
    ios::sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < 2 * n; i++)
        cin >> q[i];
    sort(q, q + 2 * n);
    for (int i = 0; i < n; i++)
        cout << q[i] << ' ' << q[2 * n - 1 - i] << '\n';
}