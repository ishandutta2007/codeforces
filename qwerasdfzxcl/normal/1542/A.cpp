#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
int a[202];

void solve(){
    int n;
    scanf("%d", &n);
    int c1 = 0, c0 = 0;
    for (int i=0;i<n*2;i++){
        scanf("%d", a+i);
        if (a[i]&1) c1++;
        else c0++;
    }
    if (c1==c0) printf("Yes\n");
    else printf("No\n");
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}