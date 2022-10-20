#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
int a[100100], c[100100];

void solve(){
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i=0;i<m;i++) c[i]=0;
    for (int i=0;i<n;i++){
        scanf("%d", a+i);
        a[i] %= m;
    }
    for (int i=0;i<n;i++) c[a[i]]++;
    int ans=0;
    for (int i=1;i<((m+1)/2);i++){
        if ((c[i] || c[m-i]) && abs(c[i]-c[m-i])<=1) ans++;
        else ans += abs(c[i]-c[m-i]);
    }
    if (c[0]) ans++;
    if (m%2==0 && c[m/2]) ans++;
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