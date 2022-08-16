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
const int N = 1e7 + 5;

int isPrime[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    fill(isPrime, isPrime + N, 1);

    for (int i = 2; i * i < N; i++) {
        if (isPrime[i] == 1) {
            for (int j = i * i; j < N; j += i) {
                isPrime[j] = i;
            }
        }
    }

    int n;
    cin >> n;

    int a;
    vector<int> ans1(n), ans2(n);

    for (int i = 0; i < n; i++) {
        cin >> a;
        if (isPrime[a] == 1) {
            ans1[i] = ans2[i] = -1;
            continue;
        }

        int pow = 1, p = isPrime[a];
        while (a % p == 0) {
            a /= p;
            pow *= p;
        }

        if (a == 1) {
            ans1[i] = ans2[i] = -1;
            continue;
        }
        ans1[i] = a;
        ans2[i] = pow;
    }

    for (int i : ans1) {
        cout << i << " ";
    } cout << "\n";
    for (int i : ans2) {
        cout << i << " ";
    } cout << "\n";
    return 0;
}