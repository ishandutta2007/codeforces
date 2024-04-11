#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

void solve(){
    int n, s;
    scanf("%d %d", &n, &s);
    printf("%d\n", s/((n/2+1)));
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}