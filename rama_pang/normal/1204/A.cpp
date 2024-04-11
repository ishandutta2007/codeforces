#include <bits/stdc++.h>
#define fi first
#define se second
#define endl "\n"
#define db(x) cout << "---> " << #x << " is " << x << endl
#define IOS ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define ALL(vec) vec.begin(), vec.end()
#define MEM(arr, val) memset(arr, val, sizeof(arr))
#define LB lower_bound
#define UB upper_bound
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
const ll MOD = 1e9 + 7;
const ll EPS = 1e-9;

ll N, M, R, C, A, B, Q;

int main() {
    IOS;
    string s; cin >> s;
    ll t = (s.size() + 1) / 2;
    ll cnt = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '1') {
            // t--;
            cnt++;
            // break;
        }
    }
    if (cnt == 1 && s.size() % 2 == 1) t--;
    if (s == "0") {
        cout << 0 << endl;
        return 0;
    }
    cout << t << endl;

}
// 0 = 0
// 1, 1-, 11 = 1
//100 - 111 = 2
//1 = 1, 100 = 2.