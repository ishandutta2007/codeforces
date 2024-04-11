#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
ll a[200200];
int nxt[200200];

int solve2(int x, int n){
    if (x==n-1) return 1;
    int ret = 2, pos = x+1;
    ll cur = a[x+1] - a[x];

    if (cur==0){
        ret = nxt[pos] - pos + 1;
        pos = nxt[pos] - 1;
    }

    //printf("\n");
    while(true){
        //printf("pos: %d\n", pos);
        int idx = lower_bound(a+pos+1, a+n, cur*2 + a[x]) - a; ///a[idx] >= 2(a[pos]-a[x]) + a[x]
        if (idx==n) break;
        ret++;
        cur = a[idx] - a[x];
        pos = idx;
    }
    return ret;
}

void solve(){
    int n;
    scanf("%d", &n);
    int prv = 0;
    for (int i=0;i<n;i++){
        scanf("%lld", a+i);
        if (a[prv]!=a[i]){
            for (int j=prv;j<i;j++) nxt[j] = i;
            prv = i;
        }
    }
    for (int j=prv;j<n;j++) nxt[j] = n;
    //for (int i=0;i<n;i++) printf("%d\n", nxt[i]);
    int ans = 0;
    for (int i=0;i<n;i++) ans = max(ans, solve2(i, n));
    printf("%d\n", n-ans);
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}