#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
pair<int, int> p[200200];
vector<int> pos;

int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i=0;i<n;i++){
        scanf("%d", &p[i].first);
        p[i].second=i;
    }
    sort(p, p+n);
    ll ans1=0, ans2=1, mod=998244353;
    for (int i=n-1;i>=n-k;i--){
        pos.push_back(p[i].second);
        ans1 += p[i].first;
    }
    sort(pos.begin(), pos.end());
    for (int i=1;i<(int)pos.size();i++){
        ans2 *= pos[i]-pos[i-1];
        ans2%=mod;
    }
    printf("%lld %lld\n", ans1, ans2);
    return 0;
}