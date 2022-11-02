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
    int n;
    cin >> n;
    if (n < 6) cout << -1 << '\n'; 
    else {
        cout << "1 2\n";
        cout << "1 3\n";
        cout << "1 4\n";
        for (int i = 4; i < n; ++i)
            cout << 3 << ' ' << i + 1 << '\n';
    }
    for (int i = 1; i < n; ++i)
        cout << 1 << ' ' << i + 1 << '\n';
    return 0;
}