#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
pair<int, int> a[100100];

void solve(){
    int n;
    scanf("%d", &n);
    for (int i=0;i<n;i++) scanf("%d", &a[i].first);
    for (int i=0;i<n;i++) a[i].second = i+1;
    sort(a, a+n);
    if (a[0].first!=a[1].first){
        printf("%d\n", a[0].second);
    }
    else printf("%d\n", a[n-1].second);
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}