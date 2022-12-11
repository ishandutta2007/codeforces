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
    int n, t;
    cin >> n >> t;
    int id = -1;
    int si, di;
    int vl = (int)1e9;
    for(int i = 0 ; i < n ; i ++ ){
        cin >> si >> di;
        while(si < t)
            si += di;
        if(si < vl){
            vl = si;
            id = i + 1;
        }
    }
    cout << id;
    return 0;
}