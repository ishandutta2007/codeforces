#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long int64;

int n;
int64 k;

int main () {
    //freopen ("input.txt", "r", stdin);
    //freopen ("output.txt", "w", stdout);

    cin >> n >> k;
    --k;
    int a[n+10];
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort (a,a+n);
    int64 x = k/n;
    int64 cnt = 0,
        num = 0;
    for (int i = 0; a[i] < a[x]; ++i) ++cnt;
    for (int i = 0; i < n; ++i) {
        if (a[i] < a[x]) continue;
        if (a[i] > a[x]) break;
        num++;
    }
    cout << a[x] << " " << a[(k - n*cnt) / num];
    return 0;
}