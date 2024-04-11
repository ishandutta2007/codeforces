#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
int a[200200];

void solve(){
    int n;
    scanf("%d", &n);
    for (int i=0;i<n;i++) scanf("%d", a+i);
    sort(a, a+n);
    int idx = 1, mn = a[1]-a[0];
    for (int i=2;i<n;i++) if (mn>a[i]-a[i-1]){
        mn = a[i]-a[i-1], idx = i;
    }
    printf("%d ", a[idx-1]);
    for (int i=idx+1;i<n;i++) printf("%d ", a[i]);
    for (int i=0;i<idx-1;i++) printf("%d ", a[i]);
    printf("%d ", a[idx]);
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