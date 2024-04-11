#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
char s[300300];

void solve(){
    int n;
    scanf("%d", &n);
    scanf("%s", s);
    char cur = 0;
    bool chk = 1;
    for (int i=0;i<n;i++){
        if (!cur && s[i]!='-') cur = s[i];
        else if (cur && s[i]!='-' && s[i]!=cur) chk = 0;
    }
    int ans = 0;
    s[n] = s[0];
    for (int i=1;i<=n;i++){
        if (s[i-1]=='-' || s[i]=='-') ans++;
        else if (chk) ans++;
    }
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