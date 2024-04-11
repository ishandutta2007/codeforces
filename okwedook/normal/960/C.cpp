#define FILES freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define FIXED cout << fixed << setprecision(20)
#define pb push_back
#define mp make_pair
#define hashmap unordered_map
#define hashset unordered_set
#define eps 1e-8
#define mod 1000000007
#define inf 1000000000000000007ll
#define intinf (1 << 31) - 1
#define f first
#define s second

#include <bits/stdc++.h>

using namespace std;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long long ll;
typedef double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<int>> graph;

int main() {
    ll x, d;
    cin >> x >> d;
    ll num = 0;
    for (num = 0; (1 << (num + 1)) - 1 <= x; ++num);
    vector<ll> arr(10000);
    ll curr = 1;
    ll ptr = 0;
    while (x > 0) {
        if (ptr + num > 10000) {
            cout << -1;
            return 0;
        }
        for (int i = ptr; i < ptr + num; ++i) arr[i] = curr;
        curr += d;
        ptr = ptr + num;
        x -= (1 << num) - 1;
        while ((1 << num) - 1 > x) --num;
    }
    cout << ptr << '\n';
    for (int i = 0; i < ptr; ++i) cout << arr[i] << ' ';
    return 0;
}