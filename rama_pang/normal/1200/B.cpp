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

ll N, M, V, E, A, B, C, T, K;
ll b[105];

int main() {
    IOS;
    cin >> T;
    while (T--) {
        cin >> N >> M >> K;
        for (int i=1; i<=N; i++) {
            cin >> b[i];
        }
        ll now=M; bool y=false;
        for (int i=1; i<N; i++) {
            now+= b[i]-max(0ll, b[i+1]-K);
            if (now<0) {cout << "NO\n"; y=true; break;}
        }
        if (!y) cout << "YES\n";
    }
}