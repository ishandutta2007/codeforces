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
const int MAXV = 2e6;

int n;
int arr[MAXV];

int main() {    
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        int num;
        scanf("%d", &num);
        ++arr[num];
    }

    int ans = 0;
    for (int i = 0; i < MAXV - 1; ++i) {
        arr[i + 1] += arr[i] / 2;
        ans += arr[i] % 2;
    }

    cout << ans << endl;

    return 0;
}