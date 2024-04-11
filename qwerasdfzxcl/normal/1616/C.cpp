#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

void solve(){
    int n;
    scanf("%d", &n);
    vector<int> a(n), b(n);
    for (int i=0;i<n;i++) scanf("%d", &a[i]);

    if (n==1) {printf("0\n"); return;}

    int ans = n;
    for (int i=0;i<n;i++){
        for (int j=i+1;j<n;j++){
            for (int k=-200;k<=200;k++){
                int x = a[i], cnt = 0;
                for (int z=i;z<n;z+=(j-i), x+=k) if (a[z]==x) cnt++;
                ans = min(ans, n-cnt);
            }
        }
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