#include "bits/stdc++.h"
#define puba push_back
#define mapa make_pair
#define ff first
#define ss second
#define bend(_x) (_x).begin(), (_x).end()
#define szof(_x) ((int) (_x).size())

using namespace std;
typedef long long ll;
typedef double dbl;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;
const int MAXN = 1e5 + 5;

int n;
int inp[MAXN];
int now[MAXN];

int main() {    
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

    cin >> n;

    inp[0] = 0;
    for (int i = 0; i < n; ++i) {
        cin >> inp[i + 1];
    }

    inp[n + 1] = 0;

    n += 2;
    

    for (int i = 0; i < n; ++i) {
        now[i] = inp[i];
        if (i) {
            now[i] = min(now[i], now[i - 1] + 1);
        }
    }

    for (int i = n - 2; i >= 0; --i) {
        now[i] = min(now[i], now[i + 1] + 1);
    }

    int nmax = *max_element(now, now + n);

    cout << nmax << endl;

    return 0;
}