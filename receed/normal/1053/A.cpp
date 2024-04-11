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
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);
#else
    //freopen("f.in", "r", stdin); 
    //freopen("f.out", "w", stdout);
#endif
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, m, k;
    cin >> n >> m >> k;
    ll g = gcd(n, k);
    ll n1 = n / g;
    k /= g;
    g = gcd(m, k);
    ll m1 = m / g;
    k /= g;
    if (k > 2) {
        printf("NO");
        return 0;
    }
    if (k == 1) {
        if (n1 < n)
            n1 *= 2;
        else if (m1 < m)
            m1 *= 2;
        else {
            printf("NO");
            return 0;
        }
    }
    printf("YES\n0 0\n%I64d 0\n0 %I64d", n1, m1);
}