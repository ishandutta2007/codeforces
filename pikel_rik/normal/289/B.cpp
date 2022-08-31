#include <bits/stdc++.h>
using namespace std;

int minMoves(vector<int> a, int d) {
    int n = a.size();
    int mod = a[0] % d, median = a[(n-1)/2];

    int c = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] % d != mod)
            return -1;
        c += abs(median - a[i]) / d;
    }
    return c;
}

int main() {
    int n, m, d;
    cin >> n >> m >> d;

    vector<int> a(n * m);
    int size = n * m;
    for (int i = 0; i < size; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    cout << minMoves(a, d);
    return 0;
}