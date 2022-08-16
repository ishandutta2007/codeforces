#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define all(x) (x).begin(), (x).end()

using namespace __gnu_pbds;
using namespace std;

using ull = unsigned long long;
using ll = long long;
template <typename T> using ordered_set = tree<T, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;

const int mod = 1e9 + 7;
const int inf = INT_MAX;
const int N = 1e2 + 5;

int n, a[2*N], cnt[N], b[2*N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < 2*n; i++) cin >> a[i];

    multiset<int> s1, s2;
    for (int i = 0; i < 2*n; i++) cnt[a[i]]++;

    for (int i = 10; i <= 99; i++) {
        if (cnt[i]) {
            if (cnt[i] == 1) {
                if (s1.size() < s2.size())
                    s1.insert(i);
                else s2.insert(i);
                cnt[i]--;
            }
            else {
                s1.insert(i);
                s2.insert(i);
                cnt[i] -= 2;
            }
        }
    }

    cout << s1.size() * s2.size() << "\n";

    for (int i = 10; i <= 99; i++) {
        if (cnt[i]) {
            while (s1.size() < n and cnt[i])
                s1.insert(i), cnt[i]--;

            while (s2.size() < n and cnt[i])
                s2.insert(i), cnt[i]--;
        }
    }

    for (int i = 0; i < 2*n; i++) {
        if (s1.find(a[i]) != s1.end())
            b[i] = 1, s1.erase(s1.find(a[i]));
        else b[i] = 2, s2.erase(s2.find(a[i]));
    }

    for (int i = 0; i < 2*n; i++)
        cout << b[i] << " ";
    return 0;
}