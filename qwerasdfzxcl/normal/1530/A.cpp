#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
char s[100100];

void solve(){
    scanf("%s", s);
    int n = 0;
    for (;s[n];)n++;
    int ans = *max_element(s, s+n) - '0';
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