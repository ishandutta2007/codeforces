#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

void solve(){
    int a, tb;
    scanf("%d %d", &a, &tb);
    int ans=0;
    int b=tb;
    if (b==1){
        b++, ans++;
    }
    int tmp=a, tc=0;
    while(tmp){
        tmp /= b;
        tc++;
    }
    ans += tc;
    b=tb;
    for (int i=1;i<=ans;i++){
        tmp=a; tc=i; b++;
        while(tmp){
            tmp /= b;
            tc++;
        }
        ans=min(tc, ans);
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