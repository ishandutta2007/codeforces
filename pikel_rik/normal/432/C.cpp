#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define all(x) (x).begin(), (x).end()

using namespace __gnu_pbds;
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ordered_set = tree<int, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;

const int mod = 1e9 + 7;
const int inf = 2e9 + 5;
const int N = 1e5 + 5;

int n, a[N], pos[N];
vector<int> primes;

bool visited[N];

void sieve(int limit = 1e5) {
    for (int i = 2; i <= limit; i++) {
        if (!visited[i]) {
            primes.push_back(i);
            for (ll j = i * (ll)i; j <= limit; j += i)
                visited[j] = true;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    sieve();

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pos[a[i]] = i;
    }

    vector<pair<int, int>> ans;
    for (int i = n; i >= 1; i--) {
        int num = i - pos[i] + 1;
        if (num == 1) continue;

        while (num != 1) {
            int lo = 0, hi = primes.size() - 1;

            while (lo < hi) {
                int mid = lo + (hi - lo + 1) / 2;
                if (primes[mid] <= num)
                    lo = mid;
                else hi = mid - 1;
            }

            ans.emplace_back(pos[i], pos[i] + primes[lo] - 1);
            int y = a[pos[i] + primes[lo] - 1];

            swap(a[pos[i]], a[pos[i] + primes[lo] - 1]);

            pos[y] = pos[i];
            pos[i] = pos[i] + primes[lo] - 1;

            num = i - pos[i] + 1;
        }
    }

    cout << ans.size() << "\n";
    for (auto p : ans) cout << p.first << " " << p.second << "\n";
    return 0;
}