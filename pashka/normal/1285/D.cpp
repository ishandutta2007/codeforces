#include <bits/stdc++.h>

#define long long long int
using namespace std;

// @author: pashka

int go(vector<int> a, int k) {
    if (a.size() == 0)
        return 0;
    if (k < 0)
        return 0;
    vector<int> a0;
    vector<int> a1;
    for (int x : a) {
        if (x >> k) {
            a1.push_back(x - (1 << k));
        } else {
            a0.push_back(x);
        }
    }
    int s0 = go(a0, k - 1);
    int s1 = go(a1, k - 1);
    if (a0.size() == 0) {
        return s1;
    } else if (a1.size() == 0) {
        return s0;
    } else {
        return (1 << k) + min(s1, s0);
    }
}

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    cout << go(a, 30);

    return 0;
}