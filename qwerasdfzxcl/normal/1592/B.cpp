#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
int a[100100], b[100100];

void solve(){
    int n, x;
    scanf("%d %d", &n, &x);
    for (int i=0;i<n;i++){
        scanf("%d", a+i);
        b[i] = a[i];
    }
    if (x<=n/2) {printf("YES\n"); return;}
    sort(b, b+n);
    vector<int> v;
    for (int i=0;i<n-x;i++) v.push_back(a[i]);
    for (int i=x;i<n;i++) v.push_back(a[i]);
    sort(v.begin(), v.end());
    for (int i=0;i<n-x;i++) a[i] = v[i];
    for (int i=x;i<n;i++) a[i] = v[i-x+n-x];
    for (int i=0;i<n;i++) if (a[i]!=b[i]) {printf("NO\n"); return;}
    printf("YES\n");
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}