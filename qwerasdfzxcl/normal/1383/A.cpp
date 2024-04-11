#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

void solve(){
    int n;
    string a, b;
    cin >> n >> a >> b;
    for (int i=0;i<n;i++) if (a[i]>b[i]){
        printf("-1\n"); return;
    }
    int ans = 0;
    for (int i=0;i<20;i++){
        int mn = 1e9;
        for (int j=0;j<n;j++) if (a[j]=='a'+i && a[j]!=b[j]){
            mn = min(mn, (int)b[j]);
        }
        if (mn==1e9) continue;
        ans++;
        for (int j=0;j<n;j++) if (a[j]=='a'+i && a[j]!=b[j]) a[j] = mn;
    }
    printf("%d\n", ans);
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}