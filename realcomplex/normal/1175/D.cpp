#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
     
using namespace std;
     
typedef long long ll;
typedef pair<int, int> pii;
     
#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
     
mt19937 rnd(chrono::steady_clock().now().time_since_epoch().count());

const int N = (int)3e5 + 9;
ll pf[N];

int main(){
    fastIO;
    int n;
    ll k;
    cin >> n >> k;
    for(int i = 1; i <= n ;i ++ ){
        cin >> pf[i];
        pf[i] += pf[i-1];
    }
    ll res = pf[n] * k;
    sort(pf + 1, pf + n);
    for(int i = 1; i < k ; i ++ )
        res -= pf[i];
    cout << res;
    return 0;
}