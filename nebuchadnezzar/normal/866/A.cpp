#include "bits/stdc++.h"
#define puba push_back
#define ff first
#define ss second
#define bend(_x) begin(_x), end(_x)
#define szof(_x) ((int) (_x).size())
#define TASK_NAME ""

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9 + 7;
const ll INFL = 1e18 + 123;
const double PI = atan2(0, -1);
mt19937 tw(960172);
ll rnd(ll x, ll y) { static uniform_int_distribution<ll> d; return d(tw) % (y - x + 1) + x; }

const int SZ = 200;
int arr[SZ];


int main() {
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);
    cerr << fixed << setprecision(15);
    cout << fixed << setprecision(15);
    
    
    /*
    arr[0] = 1;

    for (int i : {2, 3}) {
        for (int j = 0; j + i < SZ; ++j) {
            arr[j + i] += arr[j];
        }
    }

    cerr << arr[102] << "\n";
    */
    /*
    for (int i = 0; i < SZ / 6; ++i) {
        cerr << arr[i * 6] << " ";
    }
    cerr << "\n";
    */
    int n;
    scanf("%d", &n);

    if (n == 1) {
        cout << "1 1\n1\n";
    } else {
        cout << (n - 1) * 6 << " 2\n2 3\n";
    }

    #ifdef LOCAL
        cerr << "time: " << clock() << endl;
    #endif
    return 0;
}