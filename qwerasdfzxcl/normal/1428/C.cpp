#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
char s[300300];

void solve(){
    scanf("%s", s);
    int n = 0;
    for (;s[n];n++);
    int ans = 0, cur = 0;
    for (int i=n-1;i>=0;i--){
        if (s[i]=='B') cur++;
        else if (!cur) ans++;
        else cur--;
    }
    if (cur&1) ans++;
    printf("%d\n", ans);
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}