#include <bits/stdc++.h>
using namespace std;

int count(vector<int> a, int n) {
    int c = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == n)
            c += 1;
    }
    return c;
}

int main() {
    int n;
    cin >> n;

    vector<int> a(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int c1 = 0, c2 = 0, pos1, pos2;
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) {
            c1 += 1;
            pos1 = i+1;
        }
        else {
            c2 += 1;
            pos2 = i+1;
        }
    }
    if (c1 == 1)
        cout << pos1;
    else
        cout << pos2;
    return 0;
}