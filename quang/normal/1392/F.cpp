#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = 1000010;

int n;
long long a[N];
long long res[N];

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }   
    vector<int> st;
    for (int i = 1; i <= n; i++) {
        if (i == 1) {
            st.push_back(i);
            continue;
        }
        long long last = a[i - 1];
        while (st.size() > 1) {
            int id = st.back();
            long long need = i - id;
            if (a[i] - need >= last + 1) {
                last++;
                a[i] -= need;
                st.pop_back();
            } else break;
        }
        if (st.size() == 1) {
            long long delta = (a[i] - last) / i;
            last += delta;
            a[i] -= delta * (i - 1);
            if (a[i] == last) {
                st.push_back(i);
            }
            else if (a[i] == last + 1) {}
            else {
                st.push_back(a[i] - last);
                a[i] = last + 1;
            }
        } else {
            if (a[i] == last) {
                st.push_back(i); 
            } else if (a[i] == last + 1) {}
            else {
                st.back() += a[i] - last - 1;
                a[i] = last + 1;
            }
        }
    }
    for (int i = n; i >= 1; i--) {
        if (i == n) res[i] = a[i];
        else {
            res[i] = res[i + 1] - 1;
            if (st.back() == i + 1) {
                st.pop_back();
                res[i]++;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << res[i] << ' ';
    }
    cout << '\n';
    return 0;
}