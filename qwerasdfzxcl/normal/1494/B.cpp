#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

void solve(){
    int n, a[4];
    scanf("%d", &n);
    for (int i=0;i<4;i++) scanf("%d", a+i);
    int bt = 0;
    int b[4];
    bool ans = 0;
    for (;bt<16;bt++){
        for (int j=0;j<4;j++){
            if (bt&(1<<j)) b[j] = 1;
            else b[j] = 0;
        }
        bool chk = 1;
        for (int k=0;k<4;k++){
            int nxt = k+1;
            if (nxt==4) nxt = 0;
            if (a[k]-b[k]-b[nxt]<0 || a[k]-b[k]-b[nxt]>n-2) chk = 0;
        }
        ans |= chk;
    }
    if (ans) printf("YES\n");
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