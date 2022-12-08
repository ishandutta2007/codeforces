#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[200009];
ll s[200009];
main(){
    ll t;
    cin>>t;
    while(t--){
        ll n, m;
        cin >> n >> m;
        ll M = 0;
        vector<pair<ll,ll> > v;
        v.push_back({0, 0});
        for(ll i = 1; i <= n; i++){
            cin >> a[i];
            s[i] = s[i-1] + a[i];
            if(s[i] > M){
                M = s[i];
                v.push_back({s[i], i});
            }
        }
        while(m--){
            ll x;
            cin >> x;
            if(s[n] <= 0 && v.back().first < x){
                cout << -1<<" ";
                continue;
            }
            ll j = 0;
            if(x > v.back().first){
                j = (x - v.back().first + s[n] - 1) / s[n];
                x -= j * s[n];
            }
            ll lo = 0, hi = v.size()-1;
            while(lo < hi){
                ll mid  = (lo + hi)/2;
                if(v[mid].first >= x) hi = mid;
                else lo = mid + 1;
            }
            cout << j * n + v[lo].second - 1<<" ";
        }
        cout<<endl;
    }


}