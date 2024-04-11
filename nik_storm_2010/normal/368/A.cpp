#include<iostream>
#include<algorithm>

using namespace std;

int a[1000];

int main() {
    int n, d, m;
    cin >> n >> d;
    for (int i = 0; i < n; i++) cin >> a[i];
    cin >> m;
    sort(a, a + n);
    int ans = 0;
    int i = 0;
    while (m != 0) {
        if (i < n) { ans += a[i]; i++; } else ans -= d;
        m--;
    }
    cout << ans << endl;
    return 0;
}