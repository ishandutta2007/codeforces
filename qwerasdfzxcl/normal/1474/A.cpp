#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
char st[100100], ans[100100];

void solve(){
    int n;
    scanf("%d", &n);
    scanf("%s", st);
    ans[0]='1';
    for (int i=1;i<n;i++){
        if (1+st[i]-'0'==(st[i-1]-'0'+ans[i-1]-'0')) ans[i]='0';
        else ans[i]='1';
    }
    for (int i=0;i<n;i++) printf("%c", ans[i]);
    printf("\n");
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}