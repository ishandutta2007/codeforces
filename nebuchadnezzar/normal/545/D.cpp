#include "bits/stdc++.h"
#define puba push_back
#define mapa make_pair
#define ff first
#define ss second
#define bend(_x) (_x).begin(), (_x).end()
#define szof(_x) ((int) (_x).size())

using namespace std;
typedef long long LL;
typedef pair <int, int> pii;

int n;
vector <LL> v;

int main() {    
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

    cin >> n;

    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        v.puba(num);
    }

    sort(bend(v));

    LL now = 0;
    int ans = 0;

    for (int i = 0; i < n; ++i) {
        if (now > v[i]) {
            ++ans;
        } else {
            now += v[i];
        }
    }

    cout << n - ans << endl;

    return 0;
}