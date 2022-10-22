#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<double,double> pdd;

const ll big = 1000000007;
const ll mod = 998244353;

ll n,m,k,T,q;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
   // freopen("input.txt","r",stdin);
   // freopen("autput.txt","w",stdout);
    ll a,b,c;

    string s;
    cin >> s;
    n = s.length();
    bool good = 1;
    for(int c1 = 0; c1 < n-1; c1++){
        if(s[c1] == s[c1+1]){
            good = 0;
        }
    }

    if(good){
        cout << n << "\n";
        return 0;
    }

    ll best = 0;
    ll now = 0;
    char prev = 'z';

    for(int c1 = 0; c1 < 2*n; c1++){
        ll i = c1%n;
        if(s[i] != prev){
            now++;
        }
        else{
            now = 1;
        }
        best = max(best,now);
        prev = s[i];
    }
    cout << best << "\n";
    return 0;
}