#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

int arr[101];

int main() {
    //ifstream cin("B.in");
    //ofstream cout("B.out");
    int n, i;
    ios::sync_with_stdio(false);
    cin >> n;
    int s = 0;
    for(i = 1; i <= n; i++) {
        cin >> arr[i];
        s += arr[i];
    }
    sort(arr + 1, arr + n + 1);
    int ans = 0;
    for(i = 1; i <= n; i++) {
        if(2 * s < 9 * n) {
            ans++;
            s -= arr[i];
            s += 5;
        }
        else
            break;
    }
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}