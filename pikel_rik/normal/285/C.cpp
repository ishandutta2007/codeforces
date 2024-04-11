#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    ll c = 0;
    for (int i = 0; i < n; i++) {
        c += abs(a[i] - (i+1));
    }

    cout << c;
    return 0;
}