#include <bits/stdc++.h>

#define MIN_INT -2147483648
#define MAX_INT 2147483647
#define MIN_LONG -9223372036854775808L
#define MAX_LONG 9223372036854775807L

#define long long long int

using namespace std;

// @author: pashka

int main() {
    ios::sync_with_stdio(false);

    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int MAX = 200001;
    vector<int> l(MAX, n + 1);
    vector<int> r(MAX, -1);
    for (int i = 0; i < n; i++) {
        l[a[i]] = min(l[a[i]], i);
        r[a[i]] = max(r[a[i]], i);
    }
    vector<int> b(n);
    vector<int> e(n);
    for (int i = 0; i < MAX; i++) {
        if (r[i] >= l[i]) {
            b[l[i]]++;
            e[r[i]]++;
        }
    }
    
    int c = 0;
    int ll, rr;
    int res;
    for (int i = 0; i < n; i++) {
        if (c == 0) {
            ll = i;
        }
        c += b[i];
        c -= e[i];
        if (c == 0) {
            rr = i;
            map<int, int> q;
            for (int j = ll; j <= rr; j++) {
                q[a[j]]++;
            }
            int m = 0;
            for (auto p : q) {
                m = max(m, p.second);
            }
            res += (rr - ll + 1) - m;
        }
    }
    cout << res;



    return 0;
}