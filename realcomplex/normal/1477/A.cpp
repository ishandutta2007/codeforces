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
    int tc;
    cin >> tc;
    for(int t = 1; t <= tc; t ++ ){
        int n;
        ll k;
        cin >> n >> k;
        vector<ll> dd;
        ll g = 0;
        ll x;
        for(int i = 0 ; i < n; i ++ ){
            cin >> x;
            dd.push_back(x);
        }
        sort(dd.begin(), dd.end());
        for(int i = 1; i < n; i ++ ){
            g = __gcd(dd[i]-dd[i-1],g);
        }
        if(((k % g) + g) % g == ((dd[0] % g) + g) % g){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
    return 0;
}