#include <cstdio>
#include <vector>   
#include <string>
#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <random>
#include <ctime>
#include <iomanip>
#include <deque>
#include <queue> 
#include <cmath>
#include <cstring>
#include <cassert>
#include <bitset>
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

vector<int> a, p, ca, ba;
vector<vector<int>> ans;

void f(int x, int z) {
    a[x] ^= 1;
    a[(x + z) / 2] ^= 1;
    a[z] ^= 1;
    ans.push_back({x, (x + z) / 2, z});
}

void go(int pos, int x) {
    if (pos == p.size()) {
        if (x == 0 && (ba.empty() || ba.size() > ca.size()))
            ba = ca;
        return;
    }
    go(pos + 1, x);
    ca.push_back(p[pos]);
    go(pos + 1, x ^ p[pos]);
    ca.pop_back();
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);
#else
    //freopen("f.in", "r", stdin); 
    //freopen("f.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int l = 0, r = n - 1;
    while (1) {
        while (r - l + 1 >= 9 && !a[l])
            l++;
        while (r - l + 1 >= 9 && !a[r])
            r--;
        if (r - l + 1 <= 8)
            break;
        if (a[l + 1] && a[l + 2])
            f(l,l + 2);
        else if (a[r - 1] && a[r - 2])
            f(r - 2, r);
        else if (a[l + 2])
            f(l, l + 4);
        else if (a[r - 2])
            f(r - 4, r);
        else if (!a[l + 1] && !a[l + 2])
            f(l, l + 6);
        else if (!a[r - 1] && !a[r - 2])
            f(r - 6, r);
        else if ((r - l + 1) % 2) {
            f(l, r);
            f(l + 1, r - 1);
        }
        else {
            f(l, r - 1);
            f(l + 1, r);
        }
    }
    int m = 0, d = r - l + 1;
    for (int i = l; i <= r; i++) {
        m |= a[i] << (i - l);
    }
    for (int i = 0; i < d; i++)
        for (int j = i + 2; j < d; j += 2) {
            p.push_back((1 << i) | (1 << ((i + j) / 2)) | (1 << j));
        }
    if (m) {
        go(0, m);
        if (ba.empty()) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES\n";
    for (int i : ba) {
        ans.emplace_back();
        for (int j = 0; j < d; j++)
            if (i & (1 << j)) {
                ans.back().push_back(l + j);
            }
    }
    cout << ans.size() << '\n';
    for (auto &pp : ans) {
        for (int i : pp)
            cout << i + 1 << ' ';
        cout << '\n';
    }
}