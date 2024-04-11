#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vi> vvi;

int sod(int n) {
    int ans = 0;
    while (n > 0) {
        ans += n % 10;
        n /= 10;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);

    int k;
    cin >> k;

    int n = 19;
    for (int i = 1; i < k; i++) {
        n += 9;
        while (sod(n) != 10)
            n += 9;
    }
    cout << n;
    return 0;
}