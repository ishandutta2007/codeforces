#include <bits/stdc++.h>
using namespace std;

int nextround(vector<int> a, int k) {
    int i;
    for (i = 0; i < k; i++) {
        if (a[i] == 0)
            return i;
    }
    for (i = k-1; i < a.size(); i++) {
        if (a[i] > a[i+1])
            return i+1;
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << nextround(a, k);
}