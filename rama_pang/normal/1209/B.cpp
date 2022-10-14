#include <bits/stdc++.h>
#define fi first
#define se second
#define db(x) cout << #x << " is " << x << "\n"
#define IOS ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> ii;
typedef pair<ll, ii> iii;
typedef vector<ll> vi;
typedef vector<ii> vii;

int main() {
    IOS;
    vector<int> vec(100000);
    int N; cin >> N;
    string s; cin >> s;
    for (auto i : s) {
        int a, b; cin >> a >> b; swap(a, b);
        int toggle = (i == '1');
        for (int d = 0; d < 100000; d++) {
            if (d >= a && (d - a) % b == 0) {
                toggle ^= 1;
            }
            vec[d] += toggle;
        }
    }
    int ans = 0;
    for (int i = 0; i < 100000; i++) {
        ans = max(ans, vec[i]);
        
    }
    cout << ans << "\n";
}