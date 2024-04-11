#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

void solve(){
    int n;
    scanf("%d", &n);
    int k=n/2020, r=n%2020;
    if (r<=k) printf("YES\n");
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