#include <bits/stdc++.h>
#define fi freopen("inp.txt", "r", stdin)
#define fo freopen("out.txt", "w", stdout)

using namespace std;

long long a[5];

int main() {
    ios_base::sync_with_stdio(0);
   // fi, fo;
    cin >> a[0] >> a[1] >> a[2];
    sort(a, a + 3);
    cout << min((a[0] + a[1] + a[2])/ 3, a[0] + a[1]);
    return 0;
}