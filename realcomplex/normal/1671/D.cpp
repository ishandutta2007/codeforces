#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)2e5 + 10;
ll a[N];

void solve(){
    int n, x;
    cin >> n >> x;
    ll low = N;
    ll high = 0 ;
    ll cum = 0;
    for(int i = 1; i <= n; i ++ ){
        cin >> a[i];
        low = min(low, a[i]);
        high = max(high, a[i]);
        if(i > 1) cum += abs(a[i] - a[i - 1]);
    }
    ll start = min({2ll * (low - 1), a[1] - 1, a[n] - 1});
    ll en = 0;
    if(x >= high){
        en = min({2ll * (x - high), abs(x - a[n]), abs(x - a[1])});
    }
    cout << cum + start + en << "\n";
}

int main(){
    fastIO;
    //freopen("in.txt","r",stdin);
    int tc;
    cin >> tc;
    for(int iq = 1; iq <= tc; iq ++ ){
        solve();
    }
    return 0;
}