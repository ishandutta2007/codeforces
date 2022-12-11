#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define INF 1e10
#define fi first
#define se second
#define mp make_pair
#define MAXN 100005

ll cnt[MAXN];

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    ll n,x;
    cin >> n >> x;
    ll v;
    for(ll j = 0;j<n;j++){
        cin >> v;
        cnt[v]++;
    }
    ll ans = 0;
    if(x == 0){
        for(ll j = 0;j<MAXN;j++){
            ans += (cnt[j]*(cnt[j]-1))/2;
        }
        cout << ans;
        exit(0);
    }
    ll c;
    for(ll j = 0;j<MAXN;j++){
        c = j^x;
        if(c>=MAXN) continue;
        ans += cnt[j]*cnt[c];
    }
    cout << ans/2;
    return 0;
}