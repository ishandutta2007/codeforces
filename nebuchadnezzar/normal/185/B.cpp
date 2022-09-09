#include <cstdio>
#include <iostream>
#include <ctime>
#include <cassert>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <bitset>
#include <stack>
#define puba push_back
#define mapa make_pair
#define ff first
#define ss second
#define bend(_x) (_x).begin(), (_x).end()
#define szof(_x) ((int) (_x).size())

using namespace std;
typedef long long LL;

long double s, a, b, c;

int main() {    
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

    cin >> s >> a >> b >> c;

    if (a + b + c == 0) {
        cout << "0 0 0\n";
        return 0;
    }

    printf("%.20lf %.20lf %.20lf\n", (double) (s * a / (a + b + c)), (double) (s * b / (a + b + c)), (double) (s * c / (a + b + c)));

    return 0;
}