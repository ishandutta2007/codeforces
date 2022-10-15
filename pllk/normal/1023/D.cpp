#include <iostream>
#include <vector>
#include <set>

using namespace std;

int n, q;
int a[202020];

int fi[202020];
int la[202020];
vector<int> ad[202020];
vector<int> re[202020];
set<int> s;

int b[202020];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        if (fi[a[i]] == 0) fi[a[i]] = i;
        la[a[i]] = i;
    }
    int gg = 0;
    for (int i = 1; i <= q; i++) {
        if (fi[i] == 0) continue;
        ad[fi[i]].push_back(i);
        re[la[i]].push_back(i);
    }
    int lol = 0;
    for (int i = 1; i <= n; i++) {
        for (auto x : ad[i]) s.insert(x);
        if (s.size() == 0) {
            if (fi[q] == 0 && lol == 0) {
                b[i] = q;
                lol = 1;
            } else {
                b[i] = 1;
            }
        } else {
            if (a[i] == 0 && fi[q] == 0 && lol == 0) {
                b[i] = q;
                lol = 1;
            } else {
                auto it = s.end();
                it--;
                b[i] = *it;
            }
        }
        for (auto x : re[i]) s.erase(x);
    }
    if (fi[q] == 0 && lol == 0) {
        cout << "NO\n";
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        if (a[i] == 0 || a[i] == b[i]) continue;
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    for (int i = 1; i <= n; i++) {
        cout << b[i] << " ";
    }
    cout << "\n";
}