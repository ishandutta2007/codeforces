#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

void solve(){
    int n, k1, k2, w, b;
    scanf("%d %d %d", &n, &k1, &k2);
    scanf("%d %d", &w, &b);
    int x1=n-k1, x2=n-k2;
    int ans1=min(k1, k2)+abs(k1-k2)/2, ans2=min(x1, x2)+abs(x1-x2)/2;
    if (ans1>=w && ans2>=b) printf("YES\n");
    else printf("NO\n");
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}