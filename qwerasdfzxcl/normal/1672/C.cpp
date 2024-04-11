#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
int a[200200];

void solve(){
    int n;
    scanf("%d", &n);
    int mn = 1e9, mx = -1e9;
    for (int i=1;i<=n;i++){
        scanf("%d", a+i);
        if (i>=2 && a[i-1]==a[i]){
            mn = min(mn, i);
            mx = max(mx, i);
        }
    }
    if (mx==mn || mn==1e9) {printf("0\n"); return;}
    printf("%d\n", max(mx-mn-1, 1));
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}