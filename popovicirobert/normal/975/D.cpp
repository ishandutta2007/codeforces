#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 220
// 44

using namespace std;

const int MAXN = (int) 2e5;

struct Point {
    int x;
    int vx, vy;
}arr[MAXN + 1];

map <pair <ll, ll>, int> mp1;
map <ll, int> mp2;

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, a, b;
    ios::sync_with_stdio(false);
    cin >> n >> a >> b;
    for(i = 1; i <= n; i++) {
        cin >> arr[i].x >> arr[i].vx >> arr[i].vy;
        mp1[{arr[i].vx, arr[i].vy}]++;
        mp2[1LL * a * arr[i].vx - arr[i].vy]++;
    }
    ll ans = 0;
    for(i = 1; i <= n; i++) {
        ans += mp2[1LL * a * arr[i].vx - arr[i].vy] - mp1[{arr[i].vx, arr[i].vy}];
    }
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}