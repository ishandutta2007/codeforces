#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const int MAXN = (int) 2e5;

int arr[MAXN + 1];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int n, s, i;
    ios::sync_with_stdio(false);
    cin >> n >> s;
    for(i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    sort(arr + 1, arr + n + 1);
    int p = (n + 1) / 2;
    ll ans = 0;
    if(arr[p] <= s) {
        for(i = p; i <= n; i++) {
            ans += max(0, s - arr[i]);
        }
    }
    else {
        for(i = 1; i <= p; i++) {
            ans += max(0, arr[i] - s);
        }
    }
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}