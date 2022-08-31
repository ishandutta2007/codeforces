#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const int inf = INT_MAX;

int query(int x, int y) {
    cout << "? " << x << ' ' << y << endl;
    int temp;
    cin >> temp;
    return temp;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n + 1);
    vector<int> visited(n + 1);

    int i = 1, j = 2;
    while (i <= n and j <= n) {
        int x = query(i, j), y = query(j, i);
        if (x > y) {
            a[i] = x;
            i = j;
            j = j + 1;
            visited[x] = 1;
        } else {
            a[j] = y;
            j = j + 1;
            visited[y] = 1;
        }
    }

    int notthere;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            notthere = i;
        }
    }

    a[min(i, j)] = notthere;

    cout << "! ";
    for (int i = 1; i <= n; i++) cout << a[i] << ' ';
    cout << endl;

    int correct;
    cin >> correct;
    return 0;
}