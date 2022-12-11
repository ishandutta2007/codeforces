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
    ll x;
    cin >> n >> x;
    multiset<ll> A;
    ll y;
    for(int i = 0 ; i < n; i ++ ){
        cin >> y;
        A.insert(y);
    }
    auto it = A.begin();
    ll p;
    ll q;
    while(it != A.end()){
        p = *it;
        q = p * 1ll * x;
        if(A.count(q)){
            A.erase(A.find(q));
            it = A.erase(it);
        }
        else{
            it ++ ;
        }
    }
    cout << A.size() << "\n";
}

int main(){
    fastIO;
    int tc;
    cin >> tc;
    int n;
    for(int iq = 1; iq <= tc; iq ++ ){
        solve();
    }
    return 0;
}