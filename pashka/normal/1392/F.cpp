#include <bits/stdc++.h>

#define long long long int
using namespace std;

// @author: pashka

int main() {
    int n;
    scanf("%d", &n);
    vector<long> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    vector<int> st;
    st.push_back(n);
    for (int i = n - 2; i >= 0; i--) {
        while (true) {
            assert(!st.empty());
            long x = st.back() - (i + 1);
            if (a[i] + x <= a[i + 1] - 1) {
                if (st.size() > 1) {
                    a[i + 1]--;
                    a[i] += x;
                    st.pop_back();
                } else {
                    //a[i] + x * y <= a[i + 1] - y
                    // (x + 1) * y <= a[i + 1] - a[i];
                    long y = (a[i + 1] - a[i]) / (x + 1);
                    a[i] += y * x;
                    a[i + 1] -= y;
                }
            } else {
                //a[i] + x == a[i + 1] - 1;
                x = a[i + 1] - a[i] - 1;
                if (x > 0) {
                    int j = st.back() - x;
                    a[j] = a[i + 1] + (j - i - 1) - 1;
                    a[i] += x;
                    if (st.back() != n)
                        st.pop_back();
                    if (j != i + 1)
                        st.push_back(j);
                }
                break;
            }
        }
        assert(a[i + 1] == a[i] || a[i + 1] == a[i] + 1);
        if (a[i + 1] == a[i]) {
            st.push_back(i + 1);
        }
    }
    st.push_back(0);
    while (st.size() > 1) {
        int x = st.back() + 1;
        st.pop_back();
        while (x != st.back()) {
            a[x] = a[x - 1] + 1;
            x++;
        }
    }
    for (long x : a) cout << x << " ";
    cout << "\n";
    return 0;
}