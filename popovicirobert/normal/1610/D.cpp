#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lsb(x) (x & (-x))
#define Test(x) cout << "Case #" << x << ": ";


using namespace std;

constexpr int MOD = (int)1e9 + 7;

inline void add(int& x, int y) {
    x += y;
    if (x >= MOD)
        x -= MOD;
}

inline void sub(int& x, int y) {
    add(x, MOD - y);
}

inline int mul(int x, int y) {
    return (1LL * x * y) % MOD;
}

inline int lgput(int a, int b) {
    int answer = 1;
    while (b) {
        if (b & 1) answer = (1LL * answer * a) % MOD;
        b >>= 1;
        a = (1LL * a * a) % MOD;
    }
    return answer;
}

int main() {
#ifdef HOME
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n;
    cin >> n;

    map<int, int> mp;
    int even = 0;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        mp[x]++;
        even += (x % 2 == 0);
    }
    
    int answer = 1;
    for (int i = 0; i < n; i++) {
        answer = (answer * 2) % MOD;
    }
    sub(answer, 1);

    vector<int> fact(n + 1, 1), invfact(n + 1, 1);
    for (int i = 1; i <= n; i++) {
        fact[i] = mul(fact[i - 1], i);
        invfact[i] = lgput(fact[i], MOD - 2);
    }

    auto comb = [&](int n, int k) {
        if (n < k) return 0;
        return mul(fact[n], mul(invfact[n - k], invfact[k]));
    };

    map<int, int> cnt;
    for (auto itr : mp) {
        int x = 0;
        while (itr.first % (1 << x) == 0) {
            x++;
        }
        if (x > 1) {
           cnt[x - 1] += itr.second;
        }
    }

    for (auto itr : cnt) {
        for (int j = 1; j <= itr.second; j += 2) {
            sub(answer, mul(comb(itr.second, j), lgput(2, even - itr.second)));
        }
        even -= itr.second;
    }

    cout << answer;

   
    return 0;
}