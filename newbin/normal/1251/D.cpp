#include<bits/stdc++.h>
#define ll long long
#define mid ((l+r)>>1)
using namespace std;
const int maxn = 2e5 + 50;
ll s; int n;
ll x[maxn], y[maxn];
vector<ll> temp;
bool check(ll lim){
    ll res = s;
    int a = 0, b = 0;
    temp.clear();
    for(int i = 0; i < n; ++i){
        if(y[i] < lim) a++, res -= x[i];
        else if(x[i] > lim) b++, res -= x[i];
        else temp.push_back(x[i]);
    }
    if(a > (n/2)) return false;
    sort(temp.begin(), temp.end());
    for(int i = 0; i < temp.size(); ++i){
        if(a < n/2) res -= temp[i], a++;
        else res -= lim;
    }
    return res >= 0;
}
int main()
{
    int T; cin>>T;
    while(T--){
        scanf("%d%I64d", &n, &s);
        for(int i = 0; i < n; ++i){
            scanf("%I64d%I64d", &x[i], &y[i]);
        }
        ll l = 0, r = 1e9+7;
        ll ans;
        while(l<=r){
            if(check(mid)) {
                //cout<<"mid:"<<mid<<endl;
                ans = mid; l = mid+1;
            }
            else r = mid-1;
        }
        printf("%I64d\n", ans);
    }
}
/*
1
3 5
1 3
1 3
1 3
*/