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

    int m1 = *min_element(a.begin(), a.end()), m2 = *max_element(a.begin(), a.end()), pos1, pos2, flag = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == m1)
            pos1 = i+1;
        if (a[i] == m2 and flag == 0) {
            pos2 = i+1;
            flag = 1;
        }
    }

    if (pos1 > pos2)
        cout << n - pos1 + pos2 - 1;
    else if (pos1 < pos2) {
        cout << n - pos1 + pos2 - 2;
    }
    return 0;
}