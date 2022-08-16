#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    if (a == 0)
        return b;
    if (b == 0)
        return a;
    if (a > b)
        return gcd(a % b, b);
    return gcd(a, b % a);
}

int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

int main() {
    int t;
    cin >> t;

    vector<vector<int>> ans(t);

    for (int k = 0; k < t; k++) {
        int x;
        cin >> x;
        ans[k] = {x-1, 1};
    }

    for (int i = 0; i < t; i++) {
        cout << ans[i][0] << " " << ans[i][1] <<"\n";
    }

    return 0;
}