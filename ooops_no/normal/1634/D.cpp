#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
#define int long long
#define ll long long

mt19937 rnd(51);

int ask(int i, int j, int k) {
    cout << "? " << i << ' ' << j << ' ' << k << endl;
    int p;
    cin >> p;
    return p;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int i = 1, j = 2, nw = -1;
        set<int> st;
        for (int k = 3; k <= n; k++) {
            int val = ask(i, j, k);
            st.insert(val);
            if (val == *st.rbegin()) {
                nw = k;
            }
        }
        if (st.size() == 1) {
            int val1 = ask(i, 3, 4), val2 = ask(j, 3, 4);
            if (max(val1, val2) > *st.rbegin() || val2 == *st.rbegin()) {
                j = nw;
            } else {
                if (val1 == *st.rbegin()) {
                    i = nw;
                    for (int k = 1; k <= n; k++) {
                        if (k == i || k == j) continue;
                        int val = ask(i, j, k);
                        st.insert(val);
                        if (val == *st.rbegin()) {
                            nw = k;
                        }
                    }
                    j = nw;
                    cout << "! " << i << " " << j << endl;
                    continue;
                }
            }
        } else {
            j = nw;
        }
        st.clear();
        for (int k = 1; k <= n; k++) {
            if (k == i || k == j) continue;
            int val = ask(i, j, k);
            st.insert(val);
            if (val == *st.rbegin()) {
                nw = k;
            }
        }
        if (st.size() > 1) i = nw;
        cout << "! " << i << " " << j << endl;
    }
    return 0;
}