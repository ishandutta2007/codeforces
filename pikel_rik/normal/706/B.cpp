#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int m = *max_element(a.begin(), a.end());
    vector<int> c(m);

    for (int i = 0; i < n; i++) {
        c[a[i]-1] += 1;
    }

    vector<int> prefix(m);
    prefix[0] = c[0];

    for (int i = 1; i < m; i++) {
        prefix[i] = prefix[i-1] + c[i];
    }

    int q;
    cin >> q;

    int temp;
    vector<int> ans(q);

    for (int i = 0; i < q; i++) {
        cin >> temp;
        if (temp > m)
            ans[i] = n;
        else
            ans[i] = prefix[temp-1];
    }

    for (int i = 0; i < q; i++) {
        cout << ans[i] << "\n";
    }
    return 0;
}