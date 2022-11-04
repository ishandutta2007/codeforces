#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define ld long double
// 217
// 44

using namespace std;

const int MAXN = (int) 3e5;

int arr[MAXN + 1];


int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for(i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    sort(arr + 1, arr + n + 1);
    ll ans = 0;
    for(i = 1; i <= n / 2; i++) {
        ans += 1LL * (arr[i] + arr[n - i + 1]) * (arr[i] + arr[n - i + 1]);
    }
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}