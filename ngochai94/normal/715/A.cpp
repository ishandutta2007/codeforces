#include <iostream>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#define mod 1000000007
#define pi acos(-1)
#define For(i, a, b) for(int i = a; i < b; i++)
#define reset(a, b) memset(a, b, sizeof(a))
using namespace std;

long long n, a, b, c, d;

int main() {
    ios::sync_with_stdio(0);
    cin >> n;
    c = 2;
    for (long long k = 1; k <= n; k++) {
        long long cur = k * k * k + 2 * k * k + k;
        d = 1;
        while (cur * d * d < c) d++;
        cout << cur * d * d - c << endl;
        c = k * d;
    }
}