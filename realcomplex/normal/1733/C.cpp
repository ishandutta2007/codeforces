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
    vector<int> a(n);
    for(int i = 0 ; i < n; i ++) {
        cin >> a[i];
    }
    int j = 0;
    for(int i = 0 ; i < n; i ++ ){
        if(a[i] % 2 == a[0] % 2 ) j = i;
    }
    vector<pii> sol;
    for(int x = 0; x < j; x ++ ){
        if(a[x] % 2 == a[j] % 2){
            sol.push_back(mp(x, j));
        }
    }
    for(int i = 1; i < n; i ++ ){
        if(a[i] % 2 != a[0] % 2){
            sol.push_back(mp(i - 1, i));
        }
    }
    cout << sol.size() << "\n";
    for(auto x : sol){
        cout << x.fi + 1 << " " << x.se + 1 << "\n";
    }
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