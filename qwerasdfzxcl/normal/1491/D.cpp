#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

void solve(){
    int a, b;
    scanf("%d %d", &a, &b);
    if (a>b){
        printf("NO\n");
        return;
    }
    int c1=__builtin_popcount(a), c2=__builtin_popcount(b);
    if (c1<c2){
        printf("NO\n");
        return;
    }
    bool test=0;
    int pt1=0, pt2=0;
    for (int i=0;i<32;i++){
        if (a&(1<<i)) pt1++;
        if (b&(1<<i)) pt2++;
        if (pt1<pt2){
            test=1;
            break;
        }
    }
    if (test) printf("NO\n");
    else printf("YES\n");
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}