#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j; i <= k; i++) 
using namespace std;
const int N = 1123;
int a[N], b[N], n, tot, stk[N * N][2];
int main() {
    scanf("%d", &n);
    L(i, 1, n) scanf("%d", &a[i]), b[i] = i;
    L(i, 1, n) L(j, 1, n - 1) if(a[j] > a[j + 1]) swap(a[j], a[j + 1]), ++tot, stk[tot][0] = b[j], stk[tot][1] = b[j + 1], swap(b[j], b[j + 1]);
    printf("%d\n", tot);
    while(tot) printf("%d %d\n", stk[tot][0], stk[tot][1]), --tot;
    return 0;
}