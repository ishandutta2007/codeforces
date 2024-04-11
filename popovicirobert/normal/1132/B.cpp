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
    int i, n, m;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n;
    ll s = 0;
    for(i = 1; i <= n; i++) {
        cin >> arr[i];
        s += arr[i];
    }
    sort(arr + 1, arr + n + 1);
    cin >> m;
    for(i = 1; i <= m; i++) {
        int q;
        cin >> q;
        cout << s - arr[n - q + 1] << "\n";
    }
    //cin.close();
    //cout.close();
    return 0;
}