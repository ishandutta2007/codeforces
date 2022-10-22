#include <bits/stdc++.h>
using namespace std;

main() {
    int tst;
    cin >> tst;
    while (tst--) {
        int n;
        cin >> n;
        vector<int> b(n);
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }
        vector<int> a(n, -1);
        vector<vector<int>> ind(n + 2);
        vector<int> par(n + 2, -1);
        for (int i = 0; i < n; ++i) {
            ind[b[i]].push_back(i + 1);
            if (b[i] == 0 || b[i] == n + 1) {
                par[b[i]] = -1;
                continue;
            }
            par[b[i]] = b[b[i] - 1];
        }
        int rt = -1;
        vector<int> used(n + 2, 0);
        for (int i = 0; i < n; ++i) {
            if (par[b[i]] != -1) {
                used[par[b[i]]] = 1;
            }
        }
        for (int i = 0; i < n; ++i) {
            if (!used[b[i]]) {
                rt = b[i];
            }
        }
        vector<int> ord;
        while (rt != -1) {
            ord.push_back(rt);
            rt = par[rt];
        }
        reverse(ord.begin(), ord.end());
        int l = 0;
        bool tp = true;
        if (ord[0] == 0) {
            tp = false;
        }
        int kans = 0;
        for (int i = 0; i < (int)ord.size(); ++i) {
            int lst = -1;
            if (i != (int)ord.size() - 1) {
                lst = ord[i + 1];
            }
            for (int j : ind[ord[i]]) {
                if (tp) {
                    kans = max(kans, j);
                }
                if (j == lst) continue;
                a[l] = j;
                l++;
            }
            if (lst != -1) {
                a[l] = lst;
                l++;
            }
            tp = !tp;
        }
        cout << kans << endl;
        for (auto elem : a) {
            cout << elem << " ";
        }
        cout << endl;
    }
    return 0;
}