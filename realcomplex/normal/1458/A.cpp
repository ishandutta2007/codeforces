#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main(){
    fastIO;
    int n, m;
    cin >> n >> m;
    ll g = 0;
    ll a;
    cin >> a;
    ll x;
    ll d;
    for(int i = 1; i < n; i ++ ){
        cin >> x;
        d=abs(x-a);
        g = __gcd(g, d);
    }
    for(int i = 0 ; i < m; i ++ ){
        cin >> x;
        cout << __gcd(x+a,g) << " ";
    }
    return 0;
}