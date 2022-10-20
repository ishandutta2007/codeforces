#include <bits/stdc++.h>

using namespace std;

const int N = 200010;

int n;
int a[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc;
    cin >> tc;
    while (tc--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        long long res = 0;
        vector<int> st;
        for (int i = n; i >= 1; i--) {
            if (!st.empty() && st.back() <= a[i]) res += a[i] - st.back();
            while (!st.empty() && st.back() <= a[i]) st.pop_back();
            st.push_back(a[i]);
        }

        cout << res << '\n';
    }   
    return 0;
}