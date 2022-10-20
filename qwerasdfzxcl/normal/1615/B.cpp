#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int cnt(int x, int i){
    int ret = x / (1<<(i+1)) * (1<<i);
    x %= (1<<(i+1));
    return ret + max(x - (1<<i), -1) + 1;
}

void solve(){
    int l, r;
    scanf("%d %d", &l, &r);
    int mx = 0;
    for (int i=0;i<30;i++){
        mx = max(mx, cnt(r, i) - cnt(l-1, i));
    }
    printf("%d\n", r-l+1 - mx);
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}