#define FILES freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define FIXED cout << fixed << setprecision(20)
#define pb push_back
#define mp make_pair
#define hashmap unordered_map
#define hashset unordered_set
#define eps 1e-9
#define mod 1000000007
#define inf 1000000000000000007ll

#include <bits/stdc++.h>

using namespace std;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<int>> graph;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> inp(m), arr(n);
    for (auto &i : inp) {
        cin >> i;
        --i;
        ++arr[i];
    }
    int minn = mod;
    for (auto i : arr) minn = min(minn, i);
    cout << minn;
    return 0;
}