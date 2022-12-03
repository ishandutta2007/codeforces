#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    //freopen("input.txt", "r", stdin);
    int a, b, c;
    cin >> a >> b >> c;
    int t = min(a, b - 1);
    t = min(t, c - 2);
    cout << 3 * t + 3;
    return 0;
}