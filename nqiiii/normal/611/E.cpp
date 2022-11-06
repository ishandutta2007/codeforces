#include <bits/stdc++.h>
using namespace std;
int n, a[3], ans, x, y, res = 1e9;
bool fd;
multiset<int> st;

void del(multiset<int>::iterator it) {
    if (*it <= a[0] + a[1]) --x;
    if (*it <= a[2]) --y;
    st.erase(it);
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < 3; ++i) scanf("%d", &a[i]);
    sort(a, a + 3);
    for (int i = 1; i <= n; ++i) {
        int x; scanf("%d", &x);
        st.insert(x);
    }
    if (*--st.end() > a[0] + a[1] + a[2]) {
        printf("-1"); return 0;
    }
    while (!st.empty() && *--st.end() > a[1] + a[2]) {
        ++ans; st.erase(--st.end());
    }
    while (!st.empty() && *--st.end() > a[0] + a[2]) {
        ++ans; st.erase(--st.end());
        multiset<int>::iterator it = st.upper_bound(a[0]);
        if (it != st.begin()) st.erase(--it);
    }
    while (!st.empty() && *--st.end() > max(a[0] + a[1], a[2])) {
        ++ans; st.erase(--st.end());
        multiset<int>::iterator it = st.upper_bound(a[1]);
        if (it != st.begin()) st.erase(--it);
    }
    for (multiset<int>::iterator it = st.begin(); it != st.end(); ++it) {
        if (*it <= a[0] + a[1]) ++x;
        if (*it <= a[2]) ++y;
    }
    res = min(res, ans + max(((int)st.size() + 1) / 2, abs(x - y)));
    for (int i = 1; i <= 100000; ++i) {
        ++ans;
        multiset<int>::iterator it = st.upper_bound(a[2]);
        if (it != st.begin()) del(--it);
        it = st.upper_bound(a[1]);
        if (it != st.begin()) del(--it);
        it = st.upper_bound(a[0]);
        if (it != st.begin()) del(--it);
        res = min(res, ans + max(((int)st.size() + 1) / 2, abs(x - y)));
    }
    printf("%d", res);
}