#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
int a[1000];

void solve(){
    int n;
    scanf("%d", &n);
    for (int i=0;i<n;i++) scanf("%d", a+i);
    sort(a, a+n);
    if (a[0]==a[n-1]){
        printf("0\n");
        return;
    }
    int ans=0;
    for (int i=1;i<n;i++) if (a[i]!=a[0]) ans++;
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