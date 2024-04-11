#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
int a[200200], b[200200];

bool solve(int x, int n){
    int cnt = 0;
    for (int i=1;i<=n;i++){
        if (cnt==x) return 1;
        if (a[i]>=x-cnt-1 && b[i]>=cnt) cnt++;
    }
    return cnt>=x;
}

void solve(){
    int n;
    scanf("%d", &n);
    for (int i=1;i<=n;i++) scanf("%d %d", a+i, b+i);

    int l = 1, r = n, ans = 1;
    while(l<=r){
        int m = (l+r)>>1;
        if (solve(m, n)) ans = m, l = m+1;
        else r = m-1;
    }
    printf("%d\n", ans);
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}