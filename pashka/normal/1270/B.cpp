#include <bits/stdc++.h>
#define long long long int
using namespace std;

// @author: pashka

void solve_test() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int ttt = 0; ttt < 2; ttt++) {

        vector<int> st;
        vector<int> mx;

        for (int i = 0; i < n; i++) {
            while (st.size() > 0 && a[st.back()] < a[i]) {
                st.pop_back();
                mx.pop_back();
            }
            st.push_back(i);
            if (st.size() == 1) {
                mx.push_back(a[i] + i);
            } else {
                mx.push_back(max(mx.back(), a[i] + i));
            }
            if (mx.back() >= a[i] + i + 1) {
                while (mx.back() != st.back() + a[st.back()]) {
                    st.pop_back();
                }
                int j = st.back();
                cout << "YES\n";
                if (ttt == 0) {
                    cout << j + 1 << " " << i + 1 << "\n";
                } else {
                    cout << n - i << " " << n - j << "\n";
                }
                return;
            }
        }

        reverse(a.begin(), a.end());
    }
    cout << "NO\n";

}

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        solve_test();
    }

    return 0;
}