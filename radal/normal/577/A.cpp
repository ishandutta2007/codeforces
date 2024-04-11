#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define endl '\n'
#define pb push_back
#define mp make_pair
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
typedef long long  int ll;
typedef pair<int,int> pll;
const long long int N=2e5+30,mod = 1e9+7,inf=1e9;
vector <int> a;
void tajz(ll n){
    ll s = sqrt(n);
    rep(i,1,s+1){
        if (n%i == 0){
            a.pb(i);
            if (n/i != i) a.pb(n/i);
        }
    }
}
int main(){
    ll n,x;
    cin >> n >> x;
    tajz(x);
    sort(a.begin(),a.end());
    ll ans=0;
    for (int u : a){
      //  cout << u << ' ';
        if (u <= n && x/u <= n) ans++;
    }
    cout << ans;
    return 0;
}