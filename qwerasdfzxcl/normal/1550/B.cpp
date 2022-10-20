#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
char s[111];

void solve(){
    int n, a, b;
    scanf("%d %d %d", &n, &a, &b);
    scanf("%s", s);
    if (b>=0){
        printf("%d\n", (a+b)*n);
        return;
    }
    int cnt = 0, prv = -1;
    for (int i=0;i<n;i++){
        if (s[i]==prv) continue;
        prv = s[i];
        cnt++;
    }
    cnt = cnt/2+1;
    printf("%d\n", a*n+b*cnt);
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}