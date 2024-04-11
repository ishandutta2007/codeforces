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
    scanf("%d%s%s", &n, &a, &b);
    for (int i = 0; i < n; i++)
        c[a[i] - '0'][b[i] - '0']++;
    printf("%lld", c[0][0] * c[1][0] + c[0][0] * c[1][1] + c[1][0] * c[0][1]);
}