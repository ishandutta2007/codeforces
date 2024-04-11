#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair <long long, int> plli;
const int N = 1e5 + 10;

long long a[N];
int t[2][N], num[2][N], ps[N];
plli b[N];
int ans[N], pred[N];

void modify(int tree_num, int x, int value, int number) {
    for (int i = x; i < N; i = (i | (i + 1))) {
        if (t[tree_num][i] < value) {
            t[tree_num][i] = value;
            num[tree_num][i] = number;
        }
    }
}

void get(int tree_num, int x, int &ans, int &pred) {
    ans = 0;
    pred = 0;
    for (int i = x; i >= 0; i = (i & (i  + 1)) - 1) {
        if (t[tree_num][i] > ans) {
            ans = t[tree_num][i];
            pred = num[tree_num][i];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int n, d;
    cin >> n >> d;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = make_pair(a[i], i);
    }
    sort(b + 1, b + n + 1);
    for (int i = 1; i <= n; i++) {
        ps[b[i].second] = i;
    }
    for (int i = n; i >= 1; i--) {
        int l = 0, r = n + 1;
        while (r - l > 1) {
            int m = (l + r) / 2;
            if (a[i] - b[m].first >= d) {
                l = m;
            } else {
                r = m;
            }
        }
        if (l != 0) {
            int get_ans, get_pred;
            get(0, l, get_ans, get_pred);
            if (get_ans + 1 > ans[i]) {
                ans[i] = get_ans + 1;
                pred[i] = get_pred;
            }
        }
        l = 0, r = n + 1;
        while (r - l > 1) {
            int m = (l + r) / 2;
            if (b[m].first - a[i] >= d) {
                r = m;
            } else {
                l = m;
            }
        }
        if (r != n + 1) {
            int get_ans, get_pred;
            get(1, N - r, get_ans, get_pred);
            if (get_ans + 1 > ans[i]) {
                ans[i] = get_ans + 1;
                pred[i] = get_pred;
            }
        }
        modify(0, ps[i], ans[i], i);
        modify(1, N - ps[i], ans[i], i);
    }
    int res = 0, num = 0;
    for (int i = 1; i <= n; i++) {
        if (ans[i] > res) {
            res = ans[i];
            num = i;
        }
    }
    cout << res << "\n";
    while (num != 0) {
        cout << num << " ";
        num = pred[num];
    }
    return 0;
}