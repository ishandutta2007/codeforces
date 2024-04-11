#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
ll a[1001000];
ll sum[1001000];
vector<ll> allsum;

void f(int l, int r){
    allsum.push_back(sum[r]-sum[l]);
    //printf("%d %d %lld\n", r, l, allsum.back());
    if (a[l]==a[r-1]) return;
    ll tmp=(a[l]+a[r-1])/2;
    int m=upper_bound(a+l, a+r, tmp)-a;
    f(l, m);
    f(m, r);
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        allsum.clear();
        int n, q;
        scanf("%d %d", &n, &q);
        for (int i=0;i<n;i++) scanf("%lld", a+i);
        sort(a, a+n);
        for (int i=0;i<n;i++) sum[i+1]=sum[i]+a[i];
        f(0, n);
        sort(allsum.begin(), allsum.end());
        //for (ll x:allsum) printf("%lld ", x);
        //printf("\n");
        while(q--){
            ll s;
            scanf("%lld", &s);
            int tmp=lower_bound(allsum.begin(), allsum.end(), s)-allsum.begin();
            if (tmp==(int)allsum.size()){
                printf("No\n");
                continue;
            }
            if (allsum[tmp]==s){
                printf("Yes\n");
            }
            else printf("No\n");
        }
    }
    return 0;
}