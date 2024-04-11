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

int func(vector<int>a, vector<int>b) {
    if (a.empty())return 0;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    b.push_back(MOD * 2);
    int ret = 0;
    vector<int>ok(a.size());
    for (int i = 0; i < a.size(); i++) {
        ok[i] = *lower_bound(b.begin(), b.end(), a[i]) == a[i];
        ret += ok[i];
    }
    int num = ret;
    int idx = 1;
    num -= ok[0];
    for (auto i : b) {
        if (a[0] >= i)continue;
        if (i == MOD * 2)break;
        while (idx < a.size() && a[idx] <= i + idx) {
            num -= ok[idx];
            idx++;
        }
        ret = max(ret, num + lower_bound(b.begin(), b.end(), i + idx) - lower_bound(b.begin(), b.end(), i));
    }
    return ret;
}

void Solve() {
    cin >> N >> M;
    vector<int>ap;
    vector<int>am;
    vector<int>bp;
    vector<int>bm;
    for (int i = 0; i < N; i++) {
        cin >> K;
        if (K < 0)am.emplace_back(-K);
        else ap.emplace_back(K);
    }
    for (int i = 0; i < M; i++) {
        cin >> K;
        if (K < 0)bm.emplace_back(-K);
        else bp.emplace_back(K);
    }
    int ans = 0;
    ans = func(ap, bp) + func(am, bm);
    cout << ans << endl;
    return ;
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