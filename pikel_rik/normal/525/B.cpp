#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;
using ull = unsigned long long;
using ll = long long;

const int mod = 1e9 + 7;
const int inf = 2e9 + 5;
const int N = 2e5 + 5;

string s;
int n, arr[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int m;
    cin >> s >> m;
    n = s.length();

    while (m--) {
        int a; cin >> a; --a;
        arr[a] += 1;
        arr[n - a + 1] -= 1;
    }

    for (int i = 1; i <= n; i++)
        arr[i] += arr[i-1];

    for (int i = 0; i < n / 2; i++) {
        if (arr[i] % 2)
            swap(s[i], s[n - i - 1]);
    }

    cout << s;
    return 0;
}