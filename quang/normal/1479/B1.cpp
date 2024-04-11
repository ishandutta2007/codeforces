#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n;
int a[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int last = -1;
    set<int> ls;
    int res = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] == last) {
            if (!(ls.size() == 1 && *ls.begin() == a[i])) {
                res++;
            }
            ls.clear();
            ls.insert(a[i]);
        } else {
            if (ls.size() == 1 && *ls.begin() == a[i]) {
                res++;
                last = a[i];
            } else {
                res++;
                ls.insert(last);
                last = a[i];
            }
            last = a[i];
        }
        // cout << "#" << i << ' ' << res << endl;
        // cout << last << endl;
        // for (int u : ls) {
        //     cout << u << ' ';
        // }
        // cout << endl;
    }

    cout << res << endl;

    auto calc = [](vector<int> &s) {
        int res = 0;
        int last = -1;
        for (int u : s) {
            res += u != last;
            last = u;
        }
        return res;
    };

    // cout << calc(x[0]) + calc(x[1]) << endl;
    return 0;
}