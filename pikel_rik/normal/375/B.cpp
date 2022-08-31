#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define all(x) (x).begin(), (x).end()

using namespace __gnu_pbds;
using namespace std;

using ull = unsigned long long;
using ll = long long;
template <typename T> using ordered_set = tree<T, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;

const int mod = 1e9 + 7;
const int inf = 2e9 + 5;
const int N = 5e3 + 5;

int n, m, arr[N][N];
string a[N];

void csort(vector<int> &a) {
    vector<int> cnt(5001);

    for (int i : a)
        cnt[i]++;

    int ptr = 0;
    for (int i = 1; i <= 5000; i++) {
        while (cnt[i]--) {
            a[ptr++] = i;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = 0; i < n; i++) {
        int len = 0;
        for (int j = 0; j < m; j++) {
            if (a[i][j] == '0') {
                for (int k = j - len, l = 1; k < j; k++, l++)
                    arr[i][k] = l;
                len = 0;
            }
            else len++;
        }
        if (len > 0) {
            for (int k = m - len, l = 1; k < m; k++, l++)
                arr[i][k] = l;
        }
    }

    int best = 0;
    for (int j = 0; j < m; j++) {
        vector<int> temp;
        for (int i = 0; i < n; i++) {
            if (arr[i][j] > 0)
                temp.push_back(arr[i][j]);
        }
        csort(temp);
        for (int i = 0; i < temp.size(); i++) {
            best = max(best, ((int)temp.size() - i) * temp[i]);
        }
    }

    cout << best << "\n";
    return 0;
}