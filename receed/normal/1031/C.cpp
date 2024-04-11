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

const int N = 100002;
int a[N], b[N], dp[N][4], p[N][4];

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);
#else
    //freopen("f.in", "r", stdin); 
    //freopen("f.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll a, b, s = 0;
    cin >> a >> b;
    while ((s + 1) * (s + 2) / 2 <= a + b)
        s++;
    vector<int> ans(s + 1);
    ll k = 0;
    for (ll i = s; i > 0; i--)
        if (i <= a) {
            a -= i;
            ans[i] = 1;
            k++;
        }
    cout << k << '\n';
    for (int i = 1; i <= s; i++)
        if (ans[i])
            cout << i << ' ';
    cout << '\n' << s - k << '\n';
    for (int i = 1; i <= s; i++)
        if (!ans[i])
            cout << i << ' ';
}