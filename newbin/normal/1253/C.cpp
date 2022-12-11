#include<bits/stdc++.h>
#define ll long long
#define lowbit(x) ((x)&(-(x)))
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
using namespace std;
const int maxn = 2e5 + 50;
ll a[maxn], sum[maxn], ans[maxn];
int main()
{
    int n, m; cin>>n>>m;
    for(int i = 1; i <= n; ++i) scanf("%I64d", &a[i]);
    sort(a+1,a+1+n);
    for(int i = 1; i <= n; ++i) {
        if(i > 1) printf(" ");
        sum[i] = sum[i-1] + a[i];
        if(i <= m) ans[i] = sum[i];
        else {
            ans[i] = ans[i-m] + sum[i];
        }
    printf("%I64d", ans[i]);
    }printf("\n");

}