#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
int col[1010][1010];

void solve(int l, int r, int k, int e){
    //printf("%d %d %d %d\n", l, r, k, e);
    if (r-l<=1) return;
    int n = r-l, cur = l;
    for (int i=0;i<k;i++){
        int nxt = cur+n/k;
        if (i+1<=n%k) nxt++;
        solve(cur, nxt, k, e-1);
        for (int j=cur;j<nxt;j++){
            for (int p=nxt;p<r;p++) col[j][p] = e;
        }
        cur = nxt;
    }
}

int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    ll tmp = 1, ans = 0;
    while(tmp<n){
        tmp *= k;
        ans++;
    }

    printf("%lld\n", ans);
    solve(0, n, k, ans);
    for (int i=0;i<n;i++){
        for (int j=i+1;j<n;j++) printf("%d ", col[i][j]);
    }
    return 0;
}