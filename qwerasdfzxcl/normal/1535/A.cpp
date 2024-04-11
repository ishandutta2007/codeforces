#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

void solve(){
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    vector<int> v = {a, b, c, d};
    sort(v.begin(), v.end());
    if (max(max(a, b), max(c, d))==v.back() && min(max(a, b), max(c, d))==v[2]){
        printf("YES\n");
    }
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