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

    ll le, ri;
    cin >> N >> le >> ri;
    ll minim = 0, maks = 0;
    for (int i = 1; i < le; i++) {
        minim += 1ll << i;
    }
    minim += N - le +  1;
    for (int i = 0; i < ri; i++) {
        maks += 1ll << i;
    }
    maks += (1ll << (ri - 1)) * (N - ri);
    cout << minim << " " << maks << endl;
}