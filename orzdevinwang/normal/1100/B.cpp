#include<bits/stdc++.h>
#define N 110000
#define R(i, j, k) for(int i = j; i <= k; i++)
#define L(i, j, k) for(int i = j; i >= k; i--) 
using namespace std;
int n, m, a[N], sum;
int ans[N << 2];
void upd(int x) {
    ans[x] = min(ans[x << 1], ans[x << 1 | 1]);
}
void add(int x, int L, int R, int wz) {
    if(L == R) return (void)(ans[x] ++);
    int mid = (L + R) / 2;
    if(wz <= mid) add(x << 1, L, mid, wz);
    else add(x << 1 | 1, mid + 1, R, wz);
    upd(x);
}
int main() {
    scanf("%d%d", &m, &n);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for(int i = 1; i <= n; i++) {
        add(1, 1, m, a[i]);
        if(ans[1] > sum) printf("1"), ++sum;
        else printf("0");
    } 
    return 0;
}