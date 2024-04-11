#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "stack"
#include "set"
#include "functional"
#include "algorithm"
#include "string"
#include "map"
#include "unordered_map"
#include "unordered_set"
#include "iomanip"
#include "cmath"
#include "random"
#include "bitset"
#include "cstdio"
#include "numeric"
#include "cassert"
#include "ctime"

using namespace std;

//constexpr long long int MOD = 1000000007;
//constexpr int MOD = 1000000007;
//constexpr int MOD = 998244353;
constexpr long long int MOD = 998244353;
constexpr double EPS = 1e-8;

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;


void Solve() {
    cin >> N;
    vector<int>v(4);
    for (auto& i : v)cin >> i;
    for (int i = 0; i < 16; i++) {
        auto w = v;
        for (int j = 0; j < 4; j++) {
            if (i >> j & 1) {
                w[j]--;
                w[(j + 3) % 4]--;
            }
        }
        if (*min_element(w.begin(), w.end()) >= 0 && *max_element(w.begin(), w.end()) <= N - 2) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    T = 1;
    cin >> T;
    while (T--) {
        Solve();
    }
}