#include <iostream>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>
#define mod 1000000007
#define pi acos(-1)
using namespace std;

long long n, ans, cur, st[200005], lis[200005];

void dfs(int x) {
    st[x] = -1;
    cur = x;
    while (!st[lis[cur]]) {
        cur = lis[cur];
        st[cur] = -1;
    }
    cur = lis[cur];
    long long two = 1;
    while (x != cur) {
        st[x] = 1;
        x = lis[x];
        ans *= 2;
        ans %= mod;
    }
    if (st[cur] != -1) return;
    while (st[cur] == -1) {
        st[cur] = 1;
        cur = lis[cur];
        two *= 2;
        two %= mod;
    }
    ans *= two + mod - 2;
    ans %= mod;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> lis[i];
    ans = 1;
    for (int i = 1; i <= n; i++) if (!st[i]) dfs(i);
    cout << ans;
}