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

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, t;
    scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 4; j++) {
            scanf("%d", &t);
            a[i] += t;
        }
    }
    int ans = 1;
    for (int i = 1; i < n; i++)
        if (a[i] > a[0])
            ans++;
    printf("%d", ans);
}