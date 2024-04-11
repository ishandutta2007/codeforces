#include <bits/stdc++.h>
#define fi freopen("inp.txt", "r", stdin)
#define fo freopen("out.txt", "w", stdout)
#define MAX
#define N 2000010

using namespace std;

int n, k, amin = N;
int a[N];

bool check(int u) {
    int sl = 0;
    for(int i = u; i < N / 2; i += u)
    sl += a[i + k] - a[i - 1];
    return (sl >= n);
}

int main() {
    //fi, fo;
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        a[x]++;
        amin = min(amin, x);
    }
    for(int i = 1; i < N; i++) a[i] += a[i - 1];
    if(amin <= k + 1) cout << amin;
    else {
        for(int i = amin; i > k; i--)
        if(check(i)) {
            cout << i;
            return 0;
        }
    }
    return 0;
}