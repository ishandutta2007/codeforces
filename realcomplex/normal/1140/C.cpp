#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main(){
    fastIO;
    int n, k;
    cin >> n >> k;
    pii sng[n];
    for(int i = 0 ; i < n; i ++ ){
        cin >> sng[i].se >> sng[i].fi;
    }
    sort(sng, sng + n);
    multiset<ll> sn;
    ll answ = 0;
    ll cur = 0;
    ll sum = 0;
    for(int j = n - 1; j >= 0 ; j -- ){
        sn.insert(sng[j].se);
        sum += sng[j].se;
        while(sn.size() > k){
            auto it = sn.begin();
            sum -= *it;
            sn.erase(it);
        }
        cur = sum * sng[j].fi;
        answ = max(answ, cur);
    }
    cout << answ;
    return 0;
}