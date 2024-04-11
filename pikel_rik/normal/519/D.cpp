#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int mod = 1e9 + 7;
const int inf = 2e9 + 5;
const int N = 1e5;

int cost[26];
map<ll, ll> m[26];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 0; i < 26; i++) cin >> cost[i];

    string s;
    cin >> s;

    ll n = s.length(), sum = 0;
    ll ans = 0;

    for (int i = 0; i < n; i++) {
        ans += m[s[i] - 'a'][sum];

        sum += cost[s[i] - 'a'];
        m[s[i] - 'a'][sum] += 1;
    }

    cout << ans << "\n";
    return 0;
}