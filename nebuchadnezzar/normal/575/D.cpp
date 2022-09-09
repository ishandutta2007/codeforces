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

int n;

int main() {    
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

    printf("2000\n");

    for (int i = 1; i <= 1000; ++i) {
        printf("%d 1 %d 2\n", i, i);
    }

    for (int i = 1000; i >= 1; --i) {
        printf("%d 1 %d 2\n", i, i);
    }

    return 0;
}