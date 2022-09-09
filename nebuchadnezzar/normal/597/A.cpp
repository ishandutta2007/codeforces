#include "bits/stdc++.h"
#define puba push_back
#define mapa make_pair
#define ff first
#define ss second
#define bend(_x) (_x).begin(), (_x).end()
#define szof(_x) ((int) (_x).size())
#define TASK_NAME aplusb

using namespace std;
typedef long long ll;
typedef pair <int, int> pii;

ll calc(ll a, ll k) {
    ll ret = a / k;
    while ((ret + 1) * k <= a) {
        ++ret;
    }
    while (ret * k > a) {
        --ret;
    }
    return ret;
}

int main() {        
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);

    ll k, a, b;
    cin >> k >> a >> b;

    
    cout << calc(b, k) - calc(a - 1, k) << endl;

    return 0;
}