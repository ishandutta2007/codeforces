#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
int a[4040], dp[2020], tmp[2020];

void solve(){
    int n;
    scanf("%d", &n);
    for (int i=1;i<=n*2;i++){
        scanf("%d", a+i);
    }
    vector<int> ran;
    int cur = 1;
    for (int i=1;i<=n*2;i++){
        bool chk = 1;
        for (int j=cur;j<i;j++) if (a[j]>a[i]) chk = 0;
        if (!chk) ran.back()++;
        else{
            ran.push_back(1);
            cur = i;
        }
    }
    fill(dp, dp+n+1, 0);
    fill(tmp, tmp+n+1, 0);
    dp[0] = 1;
    for (auto &x:ran){
        //printf("%d\n", x);
        for (int i=0;i<=n;i++){
            if (i+x>n) break;
            tmp[i+x] |= dp[i];
        }
        for (int i=0;i<=n;i++) dp[i] |= tmp[i], tmp[i] = 0;
    }
    if (dp[n]) printf("YES\n");
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