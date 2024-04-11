#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

void solve(){
    int n, x = 0;
    scanf("%d", &n);
    for (int i=0;i<n;i++){
        int y;
        scanf("%d", &y);
        x += y;
    }
    if (x%n==0) printf("0\n");
    else printf("1\n");
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}