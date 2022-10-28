#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
const int MAXN = 110, ALP = 26, MAXL = 20, INF = 1e9+10;

void solve(){
    ll n, r; cin >> n >> r;
    if (n <= 1) { cout << "1\n"; return; }
    ll res=0;
    if(n<=r){r=n-1; res=1;}
    printf("%lld\n",res+((1+r)*(r-1+1))/2);
}
int main(){
    int t=0; cin >> t;
    while (t--) solve();
}