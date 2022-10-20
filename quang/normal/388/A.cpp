#include <bits/stdc++.h>
#define Task "A"
#define fi freopen(Task".inp", "r", stdin)
#define fo freopen(Task".out", "w", stdout)

using namespace std;

int n;
int a[110];

bool Check(int x) {
    for(int i = 1; i <= n; i++)
        if(a[i] < (i - 1) / x) return 0;
    return 1;
}

int main() {
    ios_base::sync_with_stdio(0);
    //fi, fo;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    int l = 0, r = n + 1;
    while(r - l > 1) {
        int m = (l + r) >> 1;
        if(Check(m)) r = m;
        else l = m;
    }
    cout << r;
    return 0;
}