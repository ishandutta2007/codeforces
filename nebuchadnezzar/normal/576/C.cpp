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

vector <pii> inp[1000];
int n;

int main() {    
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

    //cin >> n;
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        int x, y;
        //cin >> x >> y;
        scanf("%d%d", &x, &y);
        inp[min(y / 1000, 999)].puba(mapa(x, i));
    }

    vector <int> v;
    for (int i = 0; i < 1000; ++i) {
        sort(bend(inp[i]));
        if (i & 1) {
            reverse(bend(inp[i]));
        }
        for (int j = 0; j < szof(inp[i]); ++j) {
            v.puba(inp[i][j].ss);
        }
    }

    for (int i = 0; i < n; ++i) {
        //cout << v[i] + 1 << " ";
        printf("%d ", v[i] + 1);
    }
    printf("\n");
    return 0;
}