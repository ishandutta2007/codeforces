#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
int a[500500], b[500500];

vector<pair<int, ll>> convert(int *a, int n, int m){
    vector<pair<int, ll>> ret;
    for (int i=1;i<=n;i++){
        int x = a[i];
        while(x%m==0) x /= m;

        if (ret.empty() || ret.back().first!=x) ret.emplace_back(x, a[i]/x);
        else ret.back().second += a[i]/x;
    }
    return ret;
}

void solve(){
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i=1;i<=n;i++) scanf("%d", a+i);
    auto v1 = convert(a, n, m);

    int k;
    scanf("%d", &k);
    for (int i=1;i<=k;i++) scanf("%d", b+i);
    auto v2 = convert(b, k, m);

    if (v1==v2) printf("Yes\n");
    else printf("No\n");
    return;
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}