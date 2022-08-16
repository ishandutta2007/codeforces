#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define all(x) (x).begin(), (x).end()

using namespace __gnu_pbds;
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;
template <typename T> using ordered_set = tree<T, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;

const int mod = 1e9 + 7;
const int inf = INT_MAX;

ll fact[16];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

//    fact[0] = 1;
//    for (int i = 1; i < 16; i++)
//        fact[i] = i * fact[i - 1] % mod;
//
//    int n;
//    cin >> n;
//
//    if (n % 2 == 0) {
//        cout << "0\n";
//        return 0;
//    }
//
//    vector<int> choose(n, 0);
//    for (int i = 0; i < n / 2; i++)
//        choose[i] = 1;
//
//    reverse(all(choose));
//    vector<int> masks(1 << n);
//
//    ll ans = 0;
//
//    do {
//        vector<int> v1, v2;
//        for (int i = 0; i < n; i++) {
//            if (choose[i])
//                v1.push_back(i);
//            else v2.push_back(i);
//        }
//
//        do {
//            int mask = 0;
//            for (int i = 0; i < n / 2; i++) {
//                mask |= (1 << ((v1[i] + i) % n));
//            }
//            masks[mask]++;
//        } while (next_permutation(all(v1)));
//
//        do {
//            int mask = 0;
//            for (int i = n / 2; i < n; i++) {
//                mask |= (1 << ((v2[i - n / 2] + i) % n));
//            }
//            ans = (ans + masks[(~mask) & ((1 << n) - 1)]) % mod;
//        } while (next_permutation(all(v2)));
//
//        fill(all(masks), 0);
//    } while (next_permutation(all(choose)));
//
//    cout << ans * fact[n] % mod << "\n"; //1 18 1800 670320 734832000 890786230 695720788 150347555

    vector<int> ans = {0, 1, 0, 18, 0, 1800, 0, 670320, 0, 734832000, 0, 890786230, 0, 695720788, 0, 150347555, 0};

    int n;
    cin >> n;

    cout << ans[n] << "\n";
    return 0;
}