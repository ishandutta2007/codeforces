#include <bits/stdc++.h>
#define fi freopen("inp.txt", "r", stdin)
#define fo freopen("out.txt", "w", stdout)

using namespace std;

const int N = 100010;

int n, x;
long long a[N];
long long sl = 0;

void Inkq() {
    for(int i = 1; i <= n; i++) cout << a[i] << " ";
    exit(0);
}

int main() {
    ios_base::sync_with_stdio(0);
    //fi, fo;
    cin >> n >> x;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = x; i; i--) {
        if(a[i] == 0) {
            a[i] = sl;
            Inkq();
        } else a[i]--, sl++;
    }
    long long gt;
    int vt = 0;
    a[0] = 100000000000;
    for(int i = 1; i <= n; i++)
        if(a[i] <= a[vt]) vt = i;
    gt = a[vt];
    sl += 1ll * gt * n;
    for(int i = 1; i <= n; i++)
        a[i] -= gt;
    for(int i = vt + 1; i <= n; i++)
        a[i]--, sl++;
    a[vt] = sl;
    Inkq();
    return 0;
}