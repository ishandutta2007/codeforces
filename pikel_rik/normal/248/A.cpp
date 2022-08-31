#include <bits/stdc++.h>
using namespace std;

void swap (int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }

    int sum1 = accumulate(a.begin(), a.end(), 0), sum2 = accumulate(b.begin(), b.end(), 0);

    cout << min(sum1, n - sum1) + min(sum2, n - sum2);
    return 0;
}