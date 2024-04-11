#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
int ans[100100];

void dnc(int n, ll k, int a0, int pos){
    //printf("%d %lld %d %d\n", n, k, a0, pos);
    int idx=0;
    ll cur=0, val=0;
    for (int i=1;i<=n-1;i++){
        if (n>63){
            idx=1; break;
        }
        idx = i;
        cur += 1LL<<(n-i-1);
        if (cur>=k) break;
    }
    if (cur<k && n<=63){
        for (int i=n-1;i>=0;i--) ans[pos+i] = n-i+a0;
        return;
    }
    for (int i=idx-1;i>=0;i--) ans[pos+i] = idx-i+a0;
    if (n<=63){
        for (int i=1;i<idx;i++) val += 1LL<<(n-i-1);
    }
    dnc(n-idx, k-val, a0+idx, pos+idx);
}

void solve(){
    int n;
    ll k;
    scanf("%d %lld", &n, &k);
    if (n<63 && k>(1LL<<(n-1))){
        printf("-1\n");
        return;
    }
    dnc(n, k, 0, 0);
    for (int i=0;i<n;i++) printf("%d ", ans[i]);
    printf("\n");
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}