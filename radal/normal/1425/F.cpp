#include <bits/stdc++.h>
#pragma GCC target ("avx2")
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
const long long int N=5e5+30,inf = 1e18;
ll ans[N];
int main(){
    ll n,n2;
    cin >> n;
    n2=n;
    cout << "? " << 1 << ' ' << n << endl;
    ll sum;
    cin >> sum;
    while (n>2){
        ll x;
        n--;
        cout << "? " << 1 << ' ' << n << endl;
        cin >> x;
        ans[n] = sum - x;
        sum = x;
    }
    cout <<"? " <<  2 << ' ' << 3 << endl;
    ll x;
    cin >> x;
    ans[1] = x-ans[2];
    ans[0] = sum-ans[1];
    cout << "! ";
    rep (i,0,n2) cout << ans[i] << ' ';
    cout << endl;
    return 0;
}