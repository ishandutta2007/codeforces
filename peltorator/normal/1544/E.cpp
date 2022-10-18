#ifdef ONPC
    #define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))

using namespace std;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

typedef long long ll;
typedef long double ld;

int solve() {
    string s;
    cin >> s;
    int n = sz(s);
    vector<int> cnt(26, 0);
    int mn = 26, mn2 = 26;
    for (int i = 0; i < n; i++) {
        int x = s[i] - 'a';
        cnt[x]++;
        if (x < mn) {
            mn2 = mn;
            mn = x;
        } else if (x > mn && x < mn2) {
            mn2 = x;
        }
    }
    if (mn2 == 26) {
        cout << s << '\n';
        return 0;
    }
    int only = 0;
    while (only < 26 && cnt[only] != 1) {
        only++;
    }
    if (only < 26) {
        cout << (char)(only + 'a');
        cnt[only]--;
        for (int i = 0; i < 26; i++) {
            while (cnt[i]) {
                cout << (char)(i + 'a');
                cnt[i]--;
            }
        }
        return 0;
    }
    if (cnt[mn] >= 2 && (cnt[mn] - 2) * 2 <= (n - 2)) {
        cout << (char)(mn + 'a') << (char)(mn + 'a');
        cnt[mn] -= 2;
        int cur = mn + 1;
        while (cur < 26) {
            while (cur < 26 && cnt[cur] == 0) {
                cur++;
            }
            if (cur == 26) {
                break;
            }
            cout << (char)(cur + 'a');
            cnt[cur]--;
            if (cnt[mn]) {
                cout << (char)(mn + 'a');
                cnt[mn]--;
            }
        }
        return 0;
    }
    if (cnt[mn] + cnt[mn2] == n) {
        cout << (char)(mn + 'a');
        cnt[mn]--;
        while (cnt[mn2]) {
            cout << (char)(mn2 + 'a');
            cnt[mn2]--;
        }
        while (cnt[mn]) {
            cout << (char)(mn + 'a');
            cnt[mn]--;
        }

        return 0;
    }
    cout << (char)(mn + 'a') << (char)(mn2 + 'a');
    cnt[mn]--;
    cnt[mn2]--;
    while (cnt[mn]) {
        cout << (char)(mn + 'a');
        cnt[mn]--;
    }
    int z = mn2 + 1;
    while (!cnt[z]) {
        z++;
    }
    cout << (char)(z + 'a');
    cnt[z]--;
    while (cnt[mn2]) {
        cout << (char)(mn2 + 'a');
        cnt[mn2]--;
    }
    for (int i = 0; i < 26; i++) {
        while (cnt[i]) {
            cout << (char)(i + 'a');
            cnt[i]--;
        }
    }
    return 0;
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int TET = 1e9;
    cin >> TET;
    for (int i = 1; i <= TET; i++) {
        if (solve()) {
            break;
        }
        cout << '\n';
        #ifdef ONPC
            cout << "__________________________" << endl;
        #endif
    }
    #ifdef ONPC
        cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
    #endif
}