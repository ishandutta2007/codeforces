#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

void solve(){
    int n;
    cin >> n;
    vector<int> p(n);
    for(int i = 0 ; i < n; i ++ ){
        cin >> p[i];
    }
    if(n == 1){
        cout << "-1\n";
        return;
    }
    set<int> can;
    for(int i = 1; i <= n; i ++ ){
        can.insert(i);
    }
    vector<int> sol(n);
    for(int i = 0 ; i < n - 2; i ++ ){
        auto it = can.begin();
        while(*it == p[i]){
            it ++ ;
        }
        sol[i] = *it;
        can.erase(it);
    }
    auto it = can.begin();
    int pp = *it;
    it ++ ;
    int qq = *it;
    if(pp > qq) swap(pp, qq);
    if(p[n - 2] == pp || p[n - 1] == qq){
        swap(pp, qq);
    }
    sol[n - 2] = pp;
    sol[n - 1] = qq;
    for(auto x : sol)
        cout << x << " ";
    cout << "\n";
}

int main(){
    fastIO;
    int tc;
    cin >> tc;
    for(int iq = 1; iq <= tc; iq ++ ){
        solve();
    }
    return 0;
}