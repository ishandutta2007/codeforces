#include <bits/stdc++.h>
#define fi first
#define se second
#define endl "\n"
#define ALL(vec) vec.begin(), vec.end()
#define db(x) cout << #x << " is " << x << endl
#define MEM(arr, val) memset(arr, val, sizeof(arr))
#define IOS ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define REP(i, s, e) for (int i = s; i <= e; i++)
#define REPR(i, s, e) for (int i = s; i >= e; i--)
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll, ll> ii;
typedef pair<ll, ii> iii;
typedef vector<ii> vii;

ll N, M, V, E, A, B, C, Q;

ll gcd(ll a, ll b) {
    if (b==0) return a;
    return gcd(b, a%b);
}
int main() {

    cin >> N >> M >> Q;
    ll G=gcd(N,M);
    ll part1=N/G;
    ll part2=M/G;
    for (int i=1; i<=Q; i++) {
        ll sx,sy,ex,ey; cin >>sx>>sy>>ex>>ey;
        ll m1,m2;
        m1= (sx==1)? sy/part1 + (sy%part1!=0) : sy/part2 + (sy%part2!=0);
        m2= (ex==1)? ey/part1 + (ey%part1!=0) : ey/part2 + (ey%part2!=0);
        if (m1==m2) {
            cout <<"YES\n";
        } else {
            cout << "NO\n";
        }
    }
}