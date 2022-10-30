#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("Os")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define ll long long int
#define endl '\n'
#define mp make_pair
#define pb push_back
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
const long long int N=2e5+30,mod = 1e9+7,inf=1e18;
int main(){
    ll T;
    cin >> T;
    while (T--){
        ll n,sum=0;
        cin >> n;
        ll a[n];
        vector<ll> ans;
        rep(i,0,n){
            cin >> a[i];
            sum+=a[i];
        }
        if (sum == 0){
            cout << "NO" << endl;
            continue;
        }
        sort(a,a+n);
        cout << "YES" << endl;
        if (sum > 0) reverse(a,a+n);
        rep(i,0,n){
            cout << a[i] << ' ';
        }
        cout << endl;
    
    }
}