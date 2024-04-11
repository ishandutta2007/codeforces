#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

ll solve(vector<ll> st){
    ll low = (ll)2e9;
    for(auto x : st){
        low = min(low, x);
    }
    ll res = st.size();
    vector<ll> cur;
    ll sum = low;
    for(auto &x : st){
        x -= low;
        if(x == 0){
            if(!cur.empty()){
                sum += solve(cur);
                cur.clear();
            }
        }
        else{
            cur.push_back(x);
        }
    }
    if(!cur.empty()) sum += solve(cur);
    return min(res, sum);
}

int main(){
    fastIO;
    int n;
    cin >> n;
    vector<ll> aa(n);
    for(int i = 0 ; i < n; i ++ ){
        cin >> aa[i];
    }
    cout << solve(aa) << "\n";
    return 0;
}