#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
int a[100100];

void solve(){
    int n, x;
    scanf("%d %d", &n, &x);
    for (int i=0;i<n;i++) scanf("%d", a+i);
    sort(a, a+n, greater<int>());
    int ans = x / (a[0]+a[1]) *2, cur = 0;
    x %= a[0]+a[1];
    while(x>0){
        x -= a[cur];
        ans++;
        cur ^= 1;
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