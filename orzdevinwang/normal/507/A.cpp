#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j; i <= k; i++) 
#define R(i, j, k) for(int i = j; i >= k; i--)
#define ll long long
#define db double
using namespace std;
const int N = 1e5 + 7;
int T, n, k, dk, cnt;
struct node {
    int val, id;
} a[N];
bool cmp(node aa, node bb) {
    return aa.val < bb.val;
}
int main() {
    scanf("%d%d", &n, &k);
    dk = k;
    L(i, 1, n) scanf("%d", &a[i].val), a[i].id = i;
    sort(a + 1, a + n + 1, cmp);
    L(i, 1, n) {
        k -= a[i].val;
        if(k >= 0) cnt++;
        else break;
    }
    printf("%d\n", cnt);
    k = dk;
    L(i, 1, n) {
        k -= a[i].val;
        if(k >= 0) printf("%d ", a[i].id);
        else break;
    }
    puts("");
    return 0;
}