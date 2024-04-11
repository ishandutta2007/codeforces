#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e4;
int d[MAXN];

bool cmp(int i, int j) {
    return d[i] > d[j];
}

main() {
    int tst;
    cin >> tst;
    while (tst--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> d[i];
        }
        vector<int> ord;
        for (int i = 0; i < n; ++i) {
            ord.push_back(i);
        }
        sort(ord.begin(), ord.end(), cmp);
        vector<int> col(n, -1);
        int c = 0;
        for (int i : ord) {
            if (col[i] != -1) continue;
            col[i] = c;
            vector<int> cur;
            cur.push_back(i);
            for (int j = 0; j < d[i]; ++j) {
                cout << "? " << i + 1 << endl;
                int v;
                cin >> v;
                v--;
                if (col[v] == -1) {
                    cur.push_back(v);
                    col[v] = c;
                } else {
                    col[i] = col[v];
                    break;
                }
            }
            if (col[i] != c) {
                for (auto j : cur) {
                    col[j] = col[i];
                }
            } else {
                c++;
            }
        }
        cout << "! ";
        for (int i = 0; i < n; ++i) {
            cout << col[i] + 1 << " ";
        }
        cout << endl;
    }
    return 0;
}