#define _CRT_SECURE_NO_WARNINGS
#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair <ll, ll> pll;
typedef long double ld;
typedef pair <ld, ld> pld;

vector<ll> decomp(ll x) {
    vector<ll> ret;
    for (ll i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            ret.pb(i);
            while(x%i==0)x/=i;
        }
    }
    if(x!=1)ret.pb(x);
    return ret;
}

int myLog(int b, ll a) {
    int cnt =0;
    while(a%b==0){
        cnt++;
        a/=b;
    }
    return cnt;
}

ll pw(ll a, ll b){
    ll ret=1;
    while(b--)ret*=a;
    return ret;
}

void solve() {
    ll p, q;
    cin>>p>>q;
    vector<ll> primes = decomp(q);
    if(p%q){
        cout<<p<<'\n';
        return;
    }
    ll bst = 1;
    for (ll x : primes){
        int pLog = myLog(x, p), qLog = myLog(x, q);
        if(qLog)bst=max(bst,p/pw(x,pLog-qLog+1));
    }
    cout<<bst<<'\n';
}

int main() {
    //fast;
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}