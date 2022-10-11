// Not my code
 
#include <bits/stdc++.h>
using namespace std;
 
#pragma GCC optimize ("O3")
#pragma GCC target ("avx2")
 
#define rep(i,a,b) for(int i = a; i<int(b);++i)
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
#define trav(a,c) for(auto a: c)
 
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pii;
 
int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); 
 
    int n, m; 
    cin >> n >> m; 
 
    vector<pii> vec;  
    rep(i,0,n){
        ll l, r; 
        cin >> l >> r;
        vec.push_back({l, r}); 
    }
 
    set<pii> s;
    rep(i,0,m){
        ll a; 
        cin >> a; 
        s.insert({a, i+1}); 
    }
 
    set<tuple<ll,ll,ll> > intervals; 
    rep(i,0,n-1){
        intervals.insert({vec[i+1].second-vec[i].first, vec[i+1].first-vec[i].second, i}); 
    }
 
    vector<ll> indexes(n-1, 0); 
    bool valid = true; 
    trav(curr_int, intervals){
        ll l, r, ii; 
        tie(r,l,ii) = curr_int; 
 
        auto it = s.lower_bound({l, 0}); 
 
        if (it == s.end() || (it->first) > r){
            valid = false;  
        }
        
        if (it != s.end()) {
            indexes[ii] = it->second; 
            s.erase(it); 
        }
    }
 
    if (!valid){
        cout << "No" << endl; 
    }
    else{
        cout << "Yes" << endl; 
        rep(i,0,sz(indexes)){
            cout << indexes[i] << " "; 
        }
        cout << endl; 
    }
}