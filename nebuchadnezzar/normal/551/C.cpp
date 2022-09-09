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
const int MAXN = 1e5 + 5;

int n, m;
int inp[MAXN];
LL arr[MAXN];

int main() {    
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> inp[i];
    }
    
    LL l = 0, r = (LL) 1e15;
    while (r - l > 1) {
        LL med = (r + l) / 2;
        //cerr << med << endl;
        for (int i = 0; i < n; ++i) {
            arr[i] = inp[i];
        }
        bool flag = true;
        LL got = 0, rest = 0;
        for (int i = n - 1; i >= 0; --i) {
            int tmp = min(rest, arr[i]);
            rest -= tmp;
            arr[i] -= tmp;
            if (!arr[i]) {
                continue;
            }
            if (med <= i + 1) {
                flag = false;
                break;
            }
            tmp = arr[i] / (med - i - 1);
            if (tmp * (med - i - 1) < arr[i]) {
                ++tmp;
            }
            got += tmp;
            if (got > m) {
                flag = false;
                break;
            }
            rest += tmp * (med - i - 1) - arr[i];
        }

        if (flag) {
            r = med;
        } else {
            l = med;
        }
    }

    cout << r << endl;

    return 0;
}