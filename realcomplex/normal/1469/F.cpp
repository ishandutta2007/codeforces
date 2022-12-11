#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const ll INF = (ll)1e12;

vector<ll> l;
ll k;

bool can(ll dist){
    ll total = 1;
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    pq.push(mp(0, 1));
    ll cd;
    ll cnt;
    ll lef, rig;
    ll nx;
    for(auto x : l){
        if(pq.empty()) break;
        cd = pq.top().fi;
        cnt = pq.top().se;
        pq.pop();
        if(cd >= dist) break;
        lef = (x-1)/2;
        rig = x/2;
        nx = cd + 2;
        if(lef > 0){
            if(nx <= dist)
                total += min(dist-nx+1,lef);
            pq.push(mp(nx,lef));
        }
        if(rig > 0){
            if(nx <= dist)
                total += min(dist-nx+1,rig);
            pq.push(mp(nx,rig));
        }
        total -= 1;
        if(cnt > 1)
            pq.push(mp(cd + 1, cnt - 1));

        if(total >= k) return true;
    }
    return false;
}

int main(){
    fastIO;
    ll n;
    cin >> n >> k;
    ll x;
    for(ll i = 0 ; i < n; i ++ ){
        cin >> x;
        l.push_back(x);
    }
    sort(l.begin(), l.end());
    reverse(l.begin(), l.end());
    ll lf = 0, rf = INF;
    ll mid ;
    while(lf < rf){
        mid = (lf + rf) / 2ll;
        if(can(mid))
            rf = mid;
        else
            lf = mid + 1;
    }
    if(lf > (ll)1e9){
        cout << "-1\n";
    }
    else{
        cout << lf << "\n";
    }
    return 0;
}