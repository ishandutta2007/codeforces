#include <bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define ll long long int
#define mp make_pair
#define pb push_back
#define rep(i,l,r) for (ll i=l; i<r; i++)
#define repr(i,r,l) for (ll i=r; i>=l; i--)
using namespace std;
const int N=1e4+10;
ll ans[N],a[N];
int main(){
    ll n,p1=0,p2=1;
    cin >> n;
    rep (i,0,n){
        ans[i] = 0;
    }
    rep (i,0,n-1){
        ll k1,k2;
        cout<<"? " <<  p1+1 << ' ' << p2+1 << endl;
        cin >> k1;
        cout<<"? " <<  p2+1 << ' ' << p1+1 << endl;
        cin >> k2;
        if (k2 > k1){
            ans[p2] = k2;
            p2 = max(p1,p2) + 1;
        }
        else{
            ans[p1] = k1;
            p1 = max(p1,p2)+1;
        }
      //  debug(ans[1]);
    }
    rep (i,0,n){
        a[i] = ans[i];
    }
    sort(a,a+n);
    ll j=-1;
    rep (i,1,n){
        if (i!= a[i]){
            j = i;
            break;
        }
//        debug(a[i]);
    }
    if (j = -1){
        j = n;
    }
    cout <<"! ";
    rep (i,0,n){
        if (ans[i]) cout << ans[i] << ' ';
        else cout << j << ' ';
    }
    cout << endl;
    return 0;
}