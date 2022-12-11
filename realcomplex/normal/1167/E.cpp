#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

mt19937 rnd(chrono::steady_clock().now().time_since_epoch().count());

const int N = (int)1e6 + 9;
int n;
int m;

ll tree[N * 4];

void upd(ll p, ll d){
    p += m;
    while(p > 0){
        tree[p] += d;
        p /= 2;
    }
}

ll query(ll l, ll r){
    l += m;
    r += m;
    ll res = 0;
    while(l <= r){ 
        if(l % 2 == 1) res += tree[l ++ ];
        if(r % 2 == 0) res += tree[r -- ];
        l /= 2;
        r /= 2;
    }
    return res;
}

bool pref[N];
bool suff[N];
vector<ll> pos[N];
int shd[N];
int main(){
    fastIO;
    ll x;
    cin >> n >> x;
    m=n+1;
    int a;
    for(int i = 0; i < n; i ++ ){
        cin >> a;
        pos[a].push_back(i);
    }
    pref[0] = true;
    ll las=-1;
    for(ll i = 1; i <= x; i ++ ){
        if(pos[i].empty()){
            pref[i]=true;
            continue;
        }
        if(las==-1){
            las=i;
            pref[i]=true;
            continue;
        }
       
        if(pos[i][0] >= pos[las].back())
            pref[i]=true;
        else
            pref[i]=false;
        las=i;
        if(!pref[i])
            break;
    }
    suff[x + 1] = true;
    las = -1;
    for(ll i= x ; i >= 1; i -- ){
        if(pos[i].empty()){
            suff[i] = true;
            continue;
        }
        if(las==-1){
            las = i;
            suff[i] = true;
            continue;
        }
        if(pos[i].back() <= pos[las][0]){
            suff[i] = true;
        }
        else{
            suff[i] = false;
        }
        las = i;
        if(!suff[i])
            break;
    }
    ll mn = n;
    for(ll i = x+1; i >= 1; i -- ){
        if(!pos[i].empty()){
            mn = min(mn,pos[i][0]);
        }
        shd[i] = mn;
        if(suff[i]){
            upd(shd[i],+1);
        }
    }
    ll res = 0;
    ll mx=0;
    for(ll i = 0 ; i <= x; i ++ ){
        if(!pref[i])
            break;
        if(suff[i+1]){
            upd(shd[i + 1], -1);
        }
        if(!pos[i].empty())
            mx=max(mx,pos[i].back());
        res += query(mx,n);
    }
    cout << res << "\n";
    return 0;
}