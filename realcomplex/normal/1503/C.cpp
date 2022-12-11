#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e5 + 10;

int main(){
    fastIO;
    int n;
    cin >> n;
    vector<pii> seg(n);
    ll cost = 0;
    for(int i = 0 ; i < n; i ++ ){
        cin >> seg[i].fi >> seg[i].se;
        cost += seg[i].se;
        seg[i].se += seg[i].fi;
    }
    sort(seg.begin(), seg.end());
    ll maxi = 0;
    for(int i = 0 ; i < n; i ++ ){
        if(i > 0){
            cost += max(0ll, seg[i].fi - maxi);
        }
        maxi = max(maxi, seg[i].se);
    }
    cout << cost << "\n";
    return 0;
}