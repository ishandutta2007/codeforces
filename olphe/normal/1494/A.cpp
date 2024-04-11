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

bool Check(string s) {
    int num = 0;
    for (auto i : s) {
        if (i == '(')num++;
        else num--;
        if (num < 0)return false;
    }
    return num == 0;
}

void Solve() {
    string s;
    cin >> s;
    int num[3] = {};
    for (auto i : s) {
        num[i - 'A']++;
    }
    for (int i = 0; i < 8; i++) {
        string t;
        for (auto j : s) {
            if (i >> (j - 'A') & 1)t.push_back('(');
            else t.push_back(')');
        }
        if (Check(t)) {
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