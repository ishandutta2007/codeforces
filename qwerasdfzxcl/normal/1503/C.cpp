/*#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
pair<ll, ll> a[100100];
ll dp[100100];
set<pair<ll, ll>> st;

ll calc(ll x, ll y){
    auto iter = st.lower_bound(make_pair(x, -1e18));
    ll ret = 1e18;
    if (iter!=st.begin()){
        --iter;
        ret = min(ret, (*iter).second+(x-(*iter).first));
        ++iter;
    }
    if (iter!=st.end()){
        ret = min(ret, (*iter).second);
    }
    ll nx = x+y, ny = ret;
    auto tmp_iter= iter;
    while(iter!=st.end()){
        ll tmpx = (*iter).first, tmpy = (*iter).second;
        ll tval=ny;
        if (tmpx>nx) tval = ny + tmpx - nx;
        if (tmpy<=tval) break;
        ++iter;
    }
    st.erase(tmp_iter, iter);
    st.insert(make_pair(nx, ny));
    return ret;
}

int main(){
    int n;
    scanf("%d", &n);
    for (int i=0;i<n;i++) scanf("%lld %lld", &a[i].first, &a[i].second);
    sort(a, a+n);
    st.insert(make_pair(a[0].first+a[0].second, 0));
    ll tmp=a[0].second;
    for (int i=1;i<n;i++){
        tmp += a[i].second;
        dp[i] = calc(a[i].first, a[i].second);
    }
    printf("%lld\n", tmp+dp[n-1]);
    return 0;
}*/
#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
pair<ll, ll> a[100100];

int main(){
    int n;
    scanf("%d", &n);
    for (int i=0;i<n;i++) scanf("%lld %lld", &a[i].first, &a[i].second);
    sort(a, a+n);
    ll mx=a[0].first+a[0].second, ans=a[0].second;
    for (int i=1;i<n;i++){
        ans += max(0LL, a[i].first-mx)+a[i].second;
        mx = max(mx, a[i].first+a[i].second);
    }
    printf("%lld\n", ans);
    return 0;
}