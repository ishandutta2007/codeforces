#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
int h[1100];

void solve(){
    int n;
    scanf("%d", &n);
    for (int i=0;i<n;i++) scanf("%d", h+i);
    ll tmp=0, tmp2=0;
    bool test=1;
    for (int i=0;i<n;i++){
        tmp2 += h[i], tmp += i;
        if (tmp2<tmp){
            test=0;
            break;
        }
    }
    if (test) printf("YES\n");
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