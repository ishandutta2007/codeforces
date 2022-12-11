#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);



set<ll> sas;
vector<ll> ele;
vector<ll> pf;

void update(int l, int r){
    if(l>r) return;
    ll cur = pf[r];
    if(l > 0) cur -= pf[l-1];
    sas.insert(cur);
    if(ele[l] == ele[r]){ // uncuttable
        return;
    }
    ll cut = (ele[l] + ele[r]) / 2;
    int it = upper_bound(ele.begin(), ele.end(), cut) - ele.begin();
    update(l,it-1);
    update(it,r);
}

void solve(){
    sas.clear();
    ele.clear();
    pf.clear();
    int n, q;
    cin >> n >> q;
    ll x;
    for(int i = 0 ; i < n; i ++ ){
        cin >> x;
        ele.push_back(x);
    }
    sort(ele.begin(), ele.end());
    for(int i = 0 ; i < ele.size(); i ++ ){
        pf.push_back(ele[i]);
        if(i){
            pf[i] += pf[i - 1];
        }
    }
    update(0, n - 1);
    ll s;
    for(int i = 1; i <= q; i ++ ){
        cin >> s;
        if(sas.count(s)){
            cout << "Yes\n";
        }
        else{
            cout << "No\n";
        }
    }
}

int main(){
    fastIO;
    int tc;
    cin >> tc;
    for(int t = 1; t <= tc; t ++ ){
        solve();
    }
}