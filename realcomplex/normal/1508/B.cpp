#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

ll getpow(int n){
    if(n > 62) return (ll)2e18;
    return (1ll << n);
}

void solve(){
    int n;
    ll k;
    cin >> n >> k;
    if(getpow(n - 1) < k){
        cout << "-1\n";
        return;
    }
    int cur = 1;
    int rem;
    int add;
    vector<int> sol;
    int len;
    int en;
    while(cur <= n){
        len = n - cur;
        en = cur;
        while(1){
            if(len == 0){
                for(int j = en; j >= cur; j -- ){
                    sol.push_back(j);
                }
                break;
            }
            if(k > getpow(len - 1)){
                k -= getpow(len - 1);
                en ++ ;
                len -- ;
            }
            else{
                for(int j = en; j >= cur; j -- ){
                    sol.push_back(j);
                }
                break;
            }
        }
        cur = en + 1;
    }
    for(auto x : sol)
        cout << x << " ";
    cout << "\n";

}

int main(){
    fastIO;
    int tc;
    cin >> tc;
    for(int iq = 1; iq <= tc; iq ++ )
        solve();
    return 0;
}