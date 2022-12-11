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
    int n, d, m;
    cin >> n >> d >> m;
    vector<ll> bad, good;
    ll a;
    for(int i = 0 ; i < n; i ++ ){
        cin >> a;
        if(a > m) bad.push_back(a);
        else good.push_back(a);
    }
    sort(good.begin(), good.end());
    sort(bad.begin(), bad.end());
    good.push_back(0ll);
    for(int i = (int)good.size() - 2; i >= 0 ; i -- )
        good[i] += good[i + 1];
    ll ban;
    ll cur = 0;
    ll res = 0;
    int pf;
    reverse(bad.begin(), bad.end());
    for(int i = 0 ; i <= (int)bad.size(); i ++ ){
        ban = 0;
        if(i > 0){
            ban = (i - 1) * 1ll * d;
        }
        if(ban <= (good.size()-1) + bad.size() - i){
            ban -= (ll)bad.size() - i;
            ban = max(ban, 0ll);
            pf = min((ll)good.size() - 1, ban);

            res = max(res, cur + good[pf]);
        }
        if(i < bad.size())
            cur += bad[i];
    }
    cout << res << "\n";
    return 0;
}