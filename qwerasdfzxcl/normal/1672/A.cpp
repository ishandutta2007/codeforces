#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

void solve(){
    int n;
    scanf("%d", &n);
    int S = 0;
    for (int i=1;i<=n;i++){
        int x;
        scanf("%d", &x);
        S += x-1;
    }
    if (S%2==0) printf("maomao90\n");
    else printf("errorgorn\n");
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}