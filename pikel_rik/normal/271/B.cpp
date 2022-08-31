#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pi;

int main() {
    ios::sync_with_stdio(false);

    vi visited(100001), primes;
    for (int i = 2; i <= 100000; i++) {
        if (visited[i] == 0) {
            primes.push_back(i);
            for (ll j = (ll)i * i; j <= 100000; j += i)
                visited[j] = 1;
        }
    }

    primes.push_back(100003);

    int n, m;
    cin >> n >> m;

    vvi a(n, vi(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];

    int cost, best = INT_MAX;

    for (int i = 0; i < n; i++) {
        cost = 0;
        for (int j = 0; j < m; j++)
            cost += *lower_bound(primes.begin(), primes.end(), a[i][j]) - a[i][j];
        best = min(best, cost);
    }

    for (int j = 0; j < m; j++) {
        cost = 0;
        for (int i = 0; i < n; i++)
            cost += *lower_bound(primes.begin(), primes.end(), a[i][j]) - a[i][j];
        best = min(best, cost);
    }

    cout << best;
    return 0;
}