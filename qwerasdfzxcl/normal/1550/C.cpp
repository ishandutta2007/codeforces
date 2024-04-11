#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
int a[200200];

bool valid(int x, int y, int z){
    if (x<y && y>z) return 1;
    if (x>y && y<z) return 1;
    return 0;
}

void solve(){
    int n;
    scanf("%d", &n);
    for (int i=0;i<n;i++) scanf("%d", a+i);
    ll ans = n-1 + n;
    for (int i=0;i<n-2;i++){
        if (a[i]<a[i+1] && a[i+1]>a[i+2]) ans++;
        else if (a[i]>a[i+1] && a[i+1]<a[i+2]) ans++;
    }
    for (int i=0;i<n-3;i++){
        if (valid(a[i], a[i+1], a[i+2]) && valid(a[i], a[i+1], a[i+3]) && valid(a[i], a[i+2], a[i+3]) && valid(a[i+1], a[i+2], a[i+3])){
            ans++;
        }
    }
    printf("%lld\n", ans);
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}