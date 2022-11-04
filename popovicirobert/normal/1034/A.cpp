#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const int MAXN = (int) 3e5;
const int MAXVAL = (int) 15 * 1e6;

int fr[MAXVAL + 1];
bool ciur[MAXVAL + 1];
int arr[MAXN + 1];

int main() {
    //ifstream cin("strava.in");
    //ofstream cout("strava.out");
    int i, n;
    ios::sync_with_stdio(false);
    cin >> n;
    int val = 0;
    for(i = 1; i <= n; i++) {
        cin >> arr[i];
        val = __gcd(val, arr[i]);
    }
    for(i = 1; i <= n; i++) {
        arr[i] /= val;
        fr[arr[i]]++;
    }
    int ans = 0;
    for(i = 2; i <= MAXVAL; i++) {
        if(ciur[i] == 0) {
            int cur = 0;
            for(ll j = 1LL * i * i; j <= MAXVAL; j += i) {
                ciur[j] = 1;
            }
            for(int j = i; j <= MAXVAL; j += i) {
                cur += fr[j];
            }
            ans = max(ans, cur);
        }
    }
    if(ans == 0) {
        cout << -1;
    }
    else {
        cout << n - ans;
    }
    //cin.close();
    //cout.close();
    return 0;
}