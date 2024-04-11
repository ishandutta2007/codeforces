#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main(){
    fastIO;
    int n;
    cin >> n;
    vector<ll> h;
    ll x;
    for(int i = 0 ; i < n; i ++ ){
        cin >> x;
        h.push_back(x);
    }
    map<int, vector<pii>> sums;
    ll vl;
    for(int i = 0 ; i < n; i ++ ){
        vl = 0;
        for(int j = i ; j >= 0 ; j -- ){
            vl += h[j];
            sums[vl].push_back(mp(j,i));
        }
    }
    vector<pii> answ;
    vector<pii> cur;
    int en = -1;
    for(auto p : sums ){
        cur.clear();
        en = -1;
        for(auto x : p.se){
            if(x.fi > en){
                en = x.se;
                cur.push_back(x);
            }
        }
        if(cur.size() > answ.size()){
            answ = cur;
        }
    }
    cout << answ.size() << "\n";
    for(auto x : answ){
        cout << x.fi+1 << " " << x.se+1 << "\n";
    }
    return 0;
}