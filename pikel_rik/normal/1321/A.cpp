#include <bits/stdc++.h>
using namespace std;

int score(vector<int> a, vector<int> p) {
    int sum = 0;
    for (int i = 0; i < a.size(); i++) {
        sum += a[i]*p[i];
    }
    return sum;
}

int main() {
    int n, c = 0, flag = 0;
    cin >> n;

    vector<int> r(n, 0), b(n, 0);
    for (int i = 0; i < n; i++)
        cin >> r[i];
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        if (r[i] != b[i])
            flag = 1;
        if (r[i] == 1 and b[i] == 0)
            c += 1;
    }

    vector<int> p(n, 1);

    if (flag == 0 or c == 0)
        cout << "-1";
    else {
        int max = 1;
        float m = score(b, p) - score(r, p);
        if (m < 0)
            cout << "1";
        else {
            while (m >= 0) {
                m -= c;
                max += 1;
            }
            cout << max;
        }
    }
    return 0;
}