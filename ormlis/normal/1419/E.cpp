#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <map>
#include <unordered_set>
#include <tuple>
#include <queue>
#include <set>
#include <cstring>
#include <functional>
#include <random>
#include <chrono>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; i < n; ++i)
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

using namespace std;

const ll INF = 1e18;
const int INFi = 2e9;
const int maxN = 1e6 + 5;
const int md = 998244353;
const int md2 = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };


vector<pair<int, int>> primes;
vector<int> ans;

void sol(int j, int res, int isk) {
    if (j == primes.size()) {
        if (res == isk) return;
        if (res == 1)
            return;
        ans.push_back(res);
        return;
    }
    range(e,primes[j].second + 1) {
        sol(j + 1, res, isk);
        res *= primes[j].first;
    }
}

void get_sol(int i) {
    if (i == primes.size()) return;
    int pij = 1;
    for(int j = 1; j <= primes[i].second; ++j) {
        pij *= primes[i].first;
        sol(i + 1, pij, 1);
    }
    get_sol(i + 1);
}

void solve() {
    int n;
    cin >> n;
    primes.clear();
    ans.clear();
    for(int i = 2; i * i <= n; ++i) {
        if (n % i == 0) primes.emplace_back(i, 0);
        while(n % i == 0) {
            primes.back().second++;
            n /= i;
        }
    }
    if (n != 1) primes.emplace_back(n, 1);
    sort(rall(primes), [] (pair<int, int> &a, pair<int, int> &b) {
        return a.second < b.second;
    });
    if (primes[0].second == 1) {
        get_sol(1);
        reverse(all(ans));
        int ee = ans.back() * primes[0].first;
        ans.push_back(ee);
        sol(1, primes[0].first, ee);
        int answ = 0;
        range(i, (int)ans.size()) {
            if (__gcd(ans[i], ans[(i+1)%(int)ans.size()]) == 1) answ++;
            cout << ans[i] << " ";
        }
        cout << "\n" << answ << "\n";
        return;
    }
    primes[0].second--;
    get_sol(0);
    reverse(all(ans));
    int pk = 1;
    range(i, primes[0].second + 1) pk *= primes[0].first;
    sol(1, pk, 1);
    int answ = 0;
        range(i, (int)ans.size()) {
            if (__gcd(ans[i], ans[(i+1)%(int)ans.size()]) == 1) answ++;
            cout << ans[i] << " ";
        }
        cout << "\n" << answ << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //cout << setprecision(15) << fixed;
    int tests = 1;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}