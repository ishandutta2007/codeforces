#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

void solve(){
    int n;
    scanf("%d", &n);
    int ans = 0;
    bool on = 0;
    for (int i=1;i<=n;i++){
        int x;
        scanf("%d", &x);
        if (!x){
            if (!on) continue;
            else on = 0;
        }
        else{
            if (on) continue;
            else ans++, on = 1;
        }
    }
    ans = min(ans, 2);
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