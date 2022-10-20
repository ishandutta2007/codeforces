#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
int a[200200];

bool chk(vector<int> &v){
    int l = 0, r = (int)v.size()-1;
    while(l<r && v[l]==v[r]) l++, r--;
    return l>=r;
}

void solve(){
    int n;
    scanf("%d", &n);
    for (int i=0;i<n;i++) scanf("%d", a+i);

    if (n==1) {printf("YES\n"); return;}

    int l = 0, r = n-1;
    while(l<r && a[l]==a[r]) l++, r--;
    if (l>=r) {printf("YES\n"); return;}

    vector<int> s, t;
    for (int i=l;i<=r;i++) if (a[i]!=a[l]) s.push_back(a[i]);
    for (int i=l;i<=r;i++) if (a[i]!=a[r]) t.push_back(a[i]);

    if (!chk(s) && !chk(t)) printf("NO\n");
    else printf("YES\n");
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}