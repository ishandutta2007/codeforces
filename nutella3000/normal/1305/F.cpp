#include<bits/stdc++.h>

#pragma GCC optimize("O3")
#pragma GCC optimize("no-stack-protector")

#define long long long
#define int long

using namespace std;
const int inf = 1e9 + 7;
const int max_n = 2e5 + 1;
static int n;
static long a[max_n];
static int ans = 0;

void scan() {
    cin >> n;
    for(int i = 0;i < n;i++) {
        cin >> a[i];
        if (a[i] % 2 == 1) ans++;
    }
}

void check(long d) {
    long new_ans = 0;
    for(int i = 0;i < n;i++) {
        if (a[i] < d) new_ans += d - a[i];
        else new_ans += min(a[i] % d, d - a[i] % d);
        if (new_ans > ans) return;
    }
    if (new_ans == 3) {
        ans++;
        ans--;
    }
    ans = (int) new_ans;
}

vector<long> factor(long b) {
    vector<long> res;
    for(int i = 2;i * i <= b;i++) {
        if (b % i == 0) res.emplace_back((long) i);
        while(b % i == 0) {
            b /= i;
        }
    }
    if (b > 1) res.emplace_back(b);
    return res;
}

void f(int id) {
    vector<long> res = factor(a[id] - 1);
    for(long i : res) check(i);
    res = factor(a[id]);
    for(long i : res) check(i);
    res = factor(a[id] + 1);
    for(long i : res) check(i);
}



void solve() {
        scan();
        for(int i = 0;i < 15;i++) {
            int id = ((rand() * 128 + rand()) % n + n) % n;
            f(id);
        }
        cout << ans;
}

signed main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    solve();
}