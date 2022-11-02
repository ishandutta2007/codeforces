#define foru(i, k, n) for(int i = k; i < n; i++)
#define pb push_back
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

vector<pll> foo(ll x) {
    vector<pll> ret;
    for (ll i = 2; i * i <= x; i++) {
        if(x%i==0){
            int cnt=0;
            while(x%i==0){
                x/=i;
                cnt++;
            }
            ret.pb({cnt,i});
        }
    }
    if(x!=1)ret.pb({1,x});
    return ret;
}

void solve() {
    ll n;
    cin>>n;
    vector<pll> decom = foo(n);
    sort(decom.rbegin(),decom.rend());
    cout<<decom[0].first<<'\n';
    foru(i,0,decom[0].first){
        ll tot = 1;
        for(pll x : decom){
            if(i>=decom[0].first-x.first)tot*=x.second;
        }
        cout<<tot<<' ';
    }
    cout<<'\n';
}

int main() {
    int t;
    cin>>t;
    while(t--)solve();
}