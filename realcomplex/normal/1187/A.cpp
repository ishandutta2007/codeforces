#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main(){
    fastIO;
    int q;
    cin >> q;
    for(int tt = 0 ; tt < q; tt ++ ){
        ll n, s , t;
        cin >> n >> s >> t;
        ll com = s + t - n;
        s -= com;
        t -= com;
        cout << max({s, t}) + 1 << "\n";
    }
    return 0;
}