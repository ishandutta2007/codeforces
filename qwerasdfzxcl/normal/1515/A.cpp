#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
int a[100100];

void solve(){
    int n, x;
    scanf("%d %d", &n, &x);
    for (int i=0;i<n;i++) scanf("%d", a+i);
    if (n==1 && x==a[0]){
        printf("NO\n");
        return;
    }
    sort(a, a+n);
    int cur=0;
    for (int i=0;i<n-1;i++){
        cur += a[i];
        if (cur==x) swap(a[i], a[i+1]);
    }
    if (cur+a[n-1]==x) printf("NO\n");
    else{
        printf("YES\n");
        for (int i=0;i<n;i++) printf("%d ", a[i]);
        printf("\n");
    }
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}