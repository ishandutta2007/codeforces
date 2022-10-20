#include <bits/stdc++.h>
#define fi freopen("inp.txt", "r", stdin)
#define fo freopen("out.txt", "w", stdout)
#define MAX
#define N 5020

using namespace std;

int n;
long long a[2010][2010], tong[N], hieu[N];

int main() {
    ios_base::sync_with_stdio(0);
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    for(int j = 1; j <= n; j++) {
        scanf("%I64d", &a[i][j]);
        tong[i + j] += a[i][j];
        hieu[i - j + n] += a[i][j];
    }
    long long even = -1, odd = -1;
    int xx1, xx2, yy1, yy2;
    for(int i = 1; i <= n; i++)
    for(int j = 1; j <= n; j++) {
        long long sum = tong[i + j] + hieu[i - j + n] - a[i][j];
        if((i + j) % 2) {
            if(odd < sum) {
                odd = sum;
                xx1 = i, yy1 = j;
            }
        }
        else {
            if(even < sum) {
                even = sum;
                xx2 = i, yy2 = j;
            }
        }
    }
    printf("%I64d\n%d %d %d %d", odd + even, xx1, yy1, xx2, yy2);
    return 0;
}