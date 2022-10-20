#include <bits/stdc++.h>
#define fi freopen("inp.txt", "r", stdin)
#define fo freopen("out.txt", "w", stdout)
#define MAX
#define N 500010

using namespace std;

int n;
int a[N];
bool check[N];

int main() {
    ios_base::sync_with_stdio(0);
    //fi, fo;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    a[0] = 0, a[n + 1] = a[n] * 2;
    int vt = n / 2 + 1, ans = n;
    for(int i = 1; i <= n / 2; i++) {
        while(a[i] * 2 > a[vt]) vt++;
        if(vt > n) break;
        ans--;
        vt++;
    }
    cout << ans;
    return 0;
}