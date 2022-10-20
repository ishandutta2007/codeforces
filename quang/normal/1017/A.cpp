#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

struct Data {
    int sum, id;
} a[N];

bool cmp(Data u, Data v) {
    if (u.sum != v.sum) {
        return u.sum > v.sum;
    }
    return u.id < v.id;
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int sum = 0;
        for (int j = 1; j <= 4; j++) {
            int u;
            cin >> u;
            sum += u;
        }
        a[i].sum = sum;
        a[i].id = i;
    }
    sort(a + 1, a + n + 1, cmp);
    int res = -1;
    for (int i = 1; i <= n; i++) {
        if (a[i].id == 1) {
            res = i;
            break;
        }
    }
    cout << res << endl;
    return 0;
}