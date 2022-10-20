#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
int a[101], cnt[101];

void solve(){
    int n;
    scanf("%d", &n);
    for (int i=0;i<n;i++){
        scanf("%d", a+i);
        cnt[abs(a[i])]++;
    }

    int ans = 0;
    ans += min(cnt[0], 1);
    for (int i=1;i<=100;i++) ans += min(cnt[i], 2);
    printf("%d\n", ans);

    for (int i=0;i<=100;i++) cnt[i] = 0;
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}