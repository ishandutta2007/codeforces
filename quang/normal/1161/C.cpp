#include <bits/stdc++.h>

using namespace std;

const int N = 100;

int n;
int a[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    if (a[1] == a[n / 2 + 1]) cout << "Bob" << endl;
    else cout << "Alice" << endl;
    return 0;
}