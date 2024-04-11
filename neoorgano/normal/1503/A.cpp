#include <bits/stdc++.h>
using namespace std;

string a, b;

main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        if (s[0] == '0' || s.back() == '0') {
            cout << "NO\n";
            continue;
        }
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            cnt += (s[i] == '0');
        }
        if (cnt % 2 == 1) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        a.clear(); b.clear();
        for (int i = 0; i < n; ++i) {
            a.push_back('_');
            b.push_back('_');
        }
        vector<int> pos;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '1') {
                pos.push_back(i);
            }
        }
        int sz = pos.size();
        for (int i = 0; i < sz / 2; ++i) {
            a[pos[i]] = b[pos[i]] = '(';
        }
        for (int i = sz / 2; i < sz; ++i) {
            a[pos[i]] = b[pos[i]] = ')';
        }
        cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '0') {
                if (cnt % 2 == 0) {
                    a[i] = '(';
                    b[i] = ')';
                } else {
                    a[i] = ')';
                    b[i] = '(';
                }
                cnt++;
            }
        }
        /**vector<int> st;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '1') {
                if (st.empty() || (i - st.back()) % 2 == 0) {
                    st.push_back(i);
                } else {
                    int j = st.back();

                }
            }
        }
        for (int i = 0; i < (int)pos.size(); ++i) {
            if (st.empty() || (pos[i] - pos[st.back()]) % 2 == 0) {
                st.push_back(i);
            }  else {
                int j = st.back();
                st.pop_back();
                a[pos[j]] = b[pos[j]] = '(';
                a[pos[i]] = b[pos[i]] = ')';
                vector<int> ind;
                for (int k = pos[j] + 1; k < pos[j + 1]; ++k) {
                    ind.push_back(k);
                }
                for (int k = pos[i - 1] + 1; k < pos[i]; ++k) {
                    ind.push_back(k);
                }
                int sz = ind.size();
                for (int k = 0; k < sz; ++k) {
                    a[ind[k]] = ')';
                    b[ind[k]] = '(';
                    if (k % 2 == 1) {
                        swap(a[ind[k]], b[ind[k]]);
                    }
                }
            }
        }*/
        cout << a << "\n" << b << "\n";
    }
    return 0;
}