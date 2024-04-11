#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second

typedef long long ll;

int main() {
    //freopen("input.txt", "r", stdin);
    set<ll> kek;
    int n;
    cin >> n;
    int rt = sqrt(n) + 1;
    for (int i = 1; i <= rt; ++i) {
        if (n % i) {
            continue;
        }
        ll len = n / i;
        ll s = (2 + i * (len - 1)) * len / 2;
        kek.insert(s);
        len = i;
        s = (2 + n / i * (len - 1)) * len / 2;
        kek.insert(s);
    }
    for (auto i : kek) {
        cout << i << ' ';
    }
    return 0;
}