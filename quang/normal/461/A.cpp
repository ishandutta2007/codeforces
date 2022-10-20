#include <bits/stdc++.h>
#define fi freopen("inp.txt", "r", stdin)
#define fo freopen("out.txt", "w", stdout)
#define MAX
#define N 300010

using namespace std;

int n;
int a[N];

int main() {
    //fi, fo;
    cin >> n;
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);
    long long ans = 0;
    for(int i = 2; i <= n; i++) {
        ans += 1ll * i * a[i - 1];
    }
    ans += 1ll * n * a[n];
    cout << ans;
    return 0;
}