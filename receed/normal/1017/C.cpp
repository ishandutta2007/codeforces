#include <cstdio>
#include <vector>   
#include <string>
#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <random>
#include <ctime>
#include <iomanip>
#include <deque>
#include <queue> 
#include <cmath>
#include <cstring> 
#include <cassert>
#include <bitset>
#include <unordered_set>
typedef long long ll;
typedef long double ld;

using namespace std;

const int N = 100001;
char a[N], b[N];
ll c[2][2];

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    scanf("%d", &n);
    int r = floor(sqrt(n));
    int t = r * (r + 1) >= n ? r : r + 1;
    for (int i = 0; i < r + 1; i++)
        for (int j = min((i + 1) * t, n); j > i * t; j--)
            printf("%d ", j);
}