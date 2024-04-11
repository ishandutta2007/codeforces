#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

void solve(){
    int n, m;
    scanf("%d %d", &n, &m);
    if (n==1 && m==1) printf("0\n");
    else if (min(n, m)==1) printf("1\n");
    else printf("2\n");
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}