#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;

ll N, arr[1000005], fwt[1000005], lhs[1000005], rhs[1000005];
map<ll,ll> cnt, mp;
vector<ll> name;

void update (ll n, ll val){
    for (; n<=N; n+=(n&(-n))){
        fwt[n]+=val;
    }
}
ll query (ll n){
    ll ret=0;
    for (; n>0; n-=(n&(-n))){
        ret+=fwt[n];
    }
    return ret;
}
int main (){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin>>N;
    for (ll i=1; i<=N; i++){
        cin >> arr[i];
        ll k= ++cnt[arr[i]];
        if (mp[cnt[arr[i]]]==0){
            mp[cnt[arr[i]]]=1;
            name.push_back(cnt[arr[i]]);
        }
        lhs[i]=k;
        // mp[cnt[arr[i]]]++;
    }
    cnt.clear();
    for (ll i=N; i>=1; i--){
        ll k= ++cnt[arr[i]];
        if (mp[cnt[arr[i]]]==0){
            mp[cnt[arr[i]]]=1;
            name.push_back(cnt[arr[i]]);
        }
        rhs[i]=k;
        // mp[cnt[arr[i]]]++;
    }
    ll total=0;
    sort(name.begin(), name.end());
    for (ll i=N; i>=1; i--){
        // cout << lhs[i] << " " << rhs[i] << " ";
        ll k=lower_bound(name.begin(), name.end(), lhs[i])-name.begin();
        // cout << k << endl;
        total+= (k==0)? 0 : query(k);
        // cout << total << endl;
        update(rhs[i], 1);
    }
    cout << total << endl;
}