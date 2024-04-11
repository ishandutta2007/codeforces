#include <bits/stdc++.h>

using namespace std;

const int N = 200010;
const int LOG = 20;
const int INF = 2e9;

int n;
int a[N];
int minVal[LOG][N];
int lg2[N];
int nxt[N];
int res[N];
int id[N];

int rmq(int l, int r) {
    int lg = lg2[r - l + 1];
    int x = minVal[lg][l];
    int y = minVal[lg][r - (1 << lg) + 1];
    return a[x] < a[y] ? x : y;
}

int findId(int low, int high, int val) {
    int u = low;
    while (high - low > 1) {
        int mid = low + high >> 1;
        int minValId = rmq(u, mid);
        if (a[minValId] * 2 < val) high = mid;
        else low = mid;
    }
    return high;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    int mn = INF, mx = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i + n] = a[i];
        mn = min(mn, a[i]);
        mx = max(mx, a[i]);
        id[i] = i;
    }

    if (mn * 2 >= mx) {
        for (int i = 1; i <= n; i++) cout << -1 << ' ';
            cout << endl;
        return 0;
    }

    lg2[1] = 0;
    for (int i = 2; i < N; i++) {
        lg2[i] = lg2[i >> 1] + 1;
    }
    for (int i = 1; i <= n * 2; i++) {
        minVal[0][i] = i;
    }
    for (int i = 1; i < LOG; i++) {
        for (int j = 1; j + (1 << i) - 1 <= n * 2; j++) {
            int x = minVal[i - 1][j];
            int y = minVal[i - 1][j + (1 << i - 1)];
            if (a[x] < a[y]) minVal[i][j] = x;
            else minVal[i][j] = y;
        }
    }
    a[n * 2 + 1] = INF;

    vector<int> st;
    for (int i = 1; i <= n * 2; i++) {
        while (!st.empty() && a[st.back()] < a[i]) {
            nxt[st.back()] = i;
            st.pop_back();
        }
        st.push_back(i);
    }

    while (!st.empty()) {
        nxt[st.back()] = n * 2 + 1;
        st.pop_back();
    }

    sort(id + 1, id + n + 1, [](int u, int v) {
        if (a[u] != a[v]) return a[u] > a[v];
        return u > v;
    }); 

    for (int i = 1; i <= n; i++) {
        int u = id[i];
        int minValId = findId(u, nxt[u], a[u]);
        if (a[minValId] * 2 < a[u]) {
            res[u] = minValId - u;
        } else {
            res[u] = res[nxt[u]] + nxt[u] - u;
        }
        res[u + n] = res[u];
    }
    for (int i = 1; i <= n; i++) cout << res[i] << ' ';
        cout << endl;
    return 0;
}