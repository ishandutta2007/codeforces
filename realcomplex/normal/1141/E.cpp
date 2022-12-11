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
    ll h, n;
    cin >> h >> n;
    vector<ll> d;
    ll x;
    ll sum = 0;
    ll mx = (ll)1e15;
    for(int i = 0 ; i < n; i ++ ){
        cin >> x;
        d.push_back(x);
        sum += x;
        if(sum + h <= 0){
            cout << i + 1;
            exit(0);
        }
        mx = min(mx, sum);
    }
    if(sum >= 0){
        cout << -1;
        exit(0);
    }
    ll ps = -sum;
    ll answ = (ll)1e18;
    ll cur;
    ll si = 0;
    for(int i = 0 ; i < n; i ++ ){
        si += d[i];
        cur = h;
        cur += si;
        answ = min(answ, (((cur + ps - 1)/ps) * n) + i + 1);
    }
    cout << answ;
    return 0;
}