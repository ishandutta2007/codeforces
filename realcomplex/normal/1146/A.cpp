#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

mt19937 rnd(chrono::steady_clock().now().time_since_epoch().count());

int main(){
    fastIO;
    string t;
    cin >> t;
    int r = 0;
    for(int i = 0 ; i < t.size(); i ++ ){
        if(t[i] == 'a')
            r ++ ;
    }
    int n = t.size();
    r = 2 * r - 1;
    cout << min(n,r);
    return 0;
}