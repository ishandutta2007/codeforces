#include <bits/stdc++.h>
using namespace std;
const int maxN = 500;
multiset<int> st;
int n, a[maxN + 10];

int Gcd(int x, int y) {
    return y ? Gcd(y, x % y) : x;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n * n; ++i) {
        int x; scanf("%d", &x);
        st.insert(x);
    }
    for (int i = 1; i <= n; ++i) {
        a[i] = *st.rbegin();
        printf("%d ", a[i]);
        st.erase(st.find(a[i]));
        for (int j = 1; j <= i - 1; ++j) {
            int t = Gcd(a[i], a[j]);
            st.erase(st.find(t));
            st.erase(st.find(t));
        }
    }
}