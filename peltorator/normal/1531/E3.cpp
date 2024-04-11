#ifdef ONPC
    #define _GLIBCXX_DEBUG
    #define deb(a) cerr << "@@@@@@@ " << #a << " = " << a << endl;
#else
    #define deb(a)
#endif
#define sz(a) ((int)((a).size()))
#include <bits/stdc++.h>
#define char unsigned char

using namespace std;
mt19937 rnd(239);
// mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

typedef long long ll;
typedef long double ld;

string s;
int ind = 0;
vector<int> b;

bool mergeSort(vector<int>& a, int l, int r) {
    if (r - l <= 1) {
        return true;
    }
    int mid = (r + l) / 2;
    if (!(mergeSort(a, l, mid))) {
        return false;
    }
    if (!(mergeSort(a, mid, r))) {
        return false;
    }
    int i = l, j = mid, k = l;
    while (i < mid && j < r) {
        if (ind == sz(s)) {
            return false;
        }
        if (s[ind] == '0') {
            b[k++] = a[i++];
        } else {
            b[k++] = a[j++];
        }
        ind++;
    }
    while (i < mid) {
        b[k++] = a[i++];
    }
    while (j < r) {
        b[k++] = a[j++];
    }
    for (int x = l; x < r; x++) {
        a[x] = b[x];
    }
    return true;
}

int solve() {
    if (!(cin >> s)) {
        return 1;
    }
    int l = 0, r = 1e6;
    while (r - l > 1) {
        int n = (r + l) / 2;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            a[i] = i;
        }
        b.assign(n, 0);
        ind = 0;
        if (mergeSort(a, 0, n)) {
            l = n;
        } else {
            r = n;
        }
    }
    int n = max(0, r - 10);
    while (++n) {
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            a[i] = i;
        }
        b.assign(n, 0);
        ind = 0;
        if (mergeSort(a, 0, n)) {
            if (ind == sz(s)) {
                vector<int> ans(n);
                for (int i = 0; i < n; i++) {
                    ans[a[i]] = i;
                }
                cout << n << endl;
                for (int i : ans) {
                    cout << i + 1 << ' ';
                }
                cout << endl;
                return 0;
            }
        }
    }
    return 0;
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int TET = 1e9;
    //cin >> TET;
    for (int i = 1; i <= TET; i++) {
        if (solve()) {
            break;
        }
        #ifdef ONPC
            cout << "__________________________" << endl;
        #endif
    }
    #ifdef ONPC
        cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
    #endif
}