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
const int N=1e2+30;
ll a[N];
int main(){
    ll n;
    cin >> n;
    rep(i,0,n){
        cin >> a[i];
    }
    if (n == 2){
        cout << 2*a[1]-a[0];
        return 0;
    }
    ll k = a[n-1]-a[n-2];
    repr(i,n-2,1){
        if (a[i] - a[i-1] != k){
            cout << a[n-1];
            return 0;
        }
    }
    cout << a[n-1]+k;
    return 0;
}