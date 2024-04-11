#include <bits/stdc++.h>
#define long long long int
using namespace std;

// @author: pashka

int main() {
    ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;
    cout << "? ";
    for (int i = 1; i <= k; i++) {
        cout << i << " ";
    }
    cout << endl;
    int x, px;
    cin >> px >> x;
    cout << "? ";
    int q = 0;
    vector<int> z;
    for (int i = 1; i <= n; i++) {
        if (i != px) {
            z.push_back(i);
            cout << i << " ";
            q++;
        }
        if (q == k) break;
    }
    cout << endl;
    int y, py;
    cin >> py >> y;

    int ls = 0;

    for (int i : z) {
        if (i == py) continue;
        cout << "? ";
        for (int j : z) {
            cout << (j == i ? px : j) << " ";
        }
        cout << endl;
        int pw, w;
        cin >> pw >> w;
        int xx = 0;
        if (pw == py) xx ^= 1;
        if (x < y) xx ^= 1;
        if (!xx) ls++;
    }
    cout << "! " << ls + 1 << endl;

    return 0;
}