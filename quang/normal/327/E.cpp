#include <bits/stdc++.h>
#define fi freopen("inp.txt", "r", stdin)
#define fo freopen("out.txt", "w", stdout)
#define MAX 1000000007
#define N 24

using namespace std;

int n, k;
int a[1 << N], b[2], ways[1 << N];
long long sum[1 << N];

int main() {
    //fi, fo;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", a + (1 << i));
    scanf("%d", &k);
    for(int i = 0; i < k; i++) scanf("%d", b + i);
    ways[0] = 1;
    for(int i = 1; i < (1 << n); i++) {
        sum[i]= sum[i - (i & -i)] + a[i & -i];
        if(sum[i] != b[0] && sum[i] != b[1])
            for(int j = i; j; j -= (j & -j))
                ways[i] = (ways[i] + ways[i - (j & -j)]) % MAX;
        else ways[i] = 0;
    }
    printf("%d", ways[(1 << n) - 1]);
}