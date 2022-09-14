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
    //freopen("wikipidia.in", "r", stdin); 
    //freopen("wikipidia.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, t;
    map<int, int> c;
    cin >> n;
    string s;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> s;
        t = 0;
        for (char ch : s)
            t ^= (1 << (ch - 'a'));
        ans += c[t];
        for (int j = 0; j < 26; j++)
            ans += c[t ^ (1 << j)];
        c[t]++;
    }
    cout << ans;
}