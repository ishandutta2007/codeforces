#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long

using namespace std;

const int MAXN = 1005;

int arr[MAXN + 1];

int main() {
    //ifstream cin("C.in");
    //ofstream cout("C.out");
    int i, j, n;
    ios::sync_with_stdio(false);
    cin >> n;
    for(i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    arr[n + 1] = 1001;
    int ans = 0;
    for(i = 0; i <= n; i++) {
        for(j = i + 2; j <= n + 1; j++) {
            if(arr[j] - arr[i] == j - i) {
                ans = max(ans, j - i - 1);
            }
        }
    }
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}