#include <bits/stdc++.h>

using namespace std;

const int N = 30;

int k;
string s, a, b;
int res[N], used[N];

bool go(int id, int aa, int bb) {
    if (id == s.size()) {
        for (int i = 0; i < k; i++) {
            if (res[i] == -1) {
                for (int j = 0; j < k; j++) {
                    if (!used[j]) {
                        used[j] = 1;
                        res[i] = j;
                        break;
                    }
                }
            }
        }
        return 1;
    }
    int foo = s[id] - 'a';
    if (res[foo] == -1) {
        int mn = (aa ? 0 : a[id] - 'a');
        int mx = (bb ? k - 1 : b[id] - 'a');
        for (int i = mn; i <= mx; i++) {
            if (!used[i]) {
                used[i] = 1;
                res[s[id] - 'a'] = i;
                if (go(id + 1, aa | (i > (a[id] - 'a')), bb | (i < (b[id] - 'a')))) {
                    return 1;
                }
                used[i] = 0;
                res[s[id] - 'a'] = -1;
            }
        }
    } else {
        if (aa == 0 && res[foo] < (a[id] - 'a')) return 0;
        if (bb == 0 && res[foo] > (b[id] - 'a')) return 0;
        return go(id + 1, aa | (res[foo] > (a[id] - 'a')), bb | (res[foo] < (b[id] - 'a')));
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc;
    cin >> tc;
    while (tc--) {
        cin >> k;
        cin >> s >> a >> b;
        memset(res, -1, sizeof res);
        memset(used, 0, sizeof used);
        if (go(0, 0, 0)) {
            cout << "YES\n";
            for (int i = 0; i < k; i++) {
                cout << (char)(res[i] + 'a');
            }
            cout << '\n';
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}