#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
vector<ll> b, c;

void solve(){
    int n;
    scanf("%d", &n);
    b.clear(); c.clear();
    for (int i=0;i<n*2;i++){
        ll x, y;
        scanf("%lld %lld", &x, &y);
        if (!x) c.push_back(abs(y));
        else b.push_back(abs(x));
    }
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());
    double ans=0;
    for (int i=0;i<n;i++){
        ans += sqrt(b[i]*b[i]+c[i]*c[i]);
    }
    printf("%.13lf\n", ans);
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}