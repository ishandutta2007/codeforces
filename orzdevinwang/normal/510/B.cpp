#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j; i <= k; i++) 
#define R(i, j, k) for(int i = j; i >= k; i--) 
#define db double 
#define ll long long
using namespace std;
const int N = 333;
int n, m, f[N * N];
int find(int x) {
    return f[x] == x ? x : f[x] = find(f[x]);
}
void merge(int x, int y) {
    if(find(x) == find(y)) {
        printf("Yes\n");
        exit(0);
    }
    else f[find(x)] = find(y);
}
char a[N][N];
#define P(i, j) ((i - 1) * m + j)
int main() {
    scanf("%d%d", &n, &m);
    L(i, 1, n * m) f[i] = i;
    L(i, 1, n) scanf("%s", a[i] + 1);
    L(i, 1, n) L(j, 1, m) {
        if(i != 1 && a[i][j] == a[i - 1][j]) merge(P(i - 1, j), P(i, j));
        if(j != 1 && a[i][j] == a[i][j - 1]) merge(P(i, j - 1), P(i, j));
    }
    printf("No\n");
    return 0;
}