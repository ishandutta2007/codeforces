#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O2")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define endl '\n'
#define pb push_back
#define rep(i,l,r) for (ll i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
typedef long long ll;
typedef pair<int,int> pll;
const long long int N=1e5+10,mod = 1e9+7,inf=1e18,dlt = 12251,maxm = 1e6+10;
ll poww(int a,int k){
    if (!k) return 1;
    if (k == 1) return a;
    ll r = poww(a,k/2);
    return (((r*r)%mod)*poww(a,k&1))%mod;
}
string binary(ll x){
    string s="";
    while (x){
        if (x%2) s='1'+s;
        else s='0'+s;
        x/=2;
    }
    return s;
}
int main(){
    ll x,d;
    cin >> x >> d;
    rep(i,1,10000){
        string s = binary(x+i);
        int cnt = 0,n = s.size();
        ll sum = 0;
        vector<int> ve;
        rep(j,0,n){
            if (s[j] == '1'){
                cnt++;
                sum += (n-j-1);
                ve.pb(n-j-1);
            }
        }
        if (cnt > i) continue;
        reverse(ve.begin(),ve.end());
        while (i-cnt){
            int k = ve.back();
            ve.pop_back();
            ve.pb(k-1);
            ve.pb(k-1);
            sum += k-2;
            cnt++;
        }
        cout << sum << endl;
        n=  ve.size();
        rep(j,0,n){
            rep(k,0,ve[j]){
                cout << 1+d*j+j << ' ';
            }
        }
        return 0;
    }
    cout << -1;
    return 0;
}