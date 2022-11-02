#include <bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("Os")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define ll long long int
#define mp make_pair
#define pb push_back
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
const int N=1e2+30;
int main(){
    ll n,a,b,c;
    cin >> n;
    ll p[n];
    cout << "? " << 1 << ' ' << 2 << endl;
    cin >> a;
    cout << "? " << 1 << ' ' << 3 << endl;
    cin >> b;
    cout << "? " << 3 << ' ' << 2 << endl;
    cin >> c;
    p[1] = a-b+c;
    p[1] /= 2;
    p[0] = a-p[1];
    p[2] = c-p[1];
    rep(i,3,n){
        ll x;
        cout << "? " << 1 << ' ' << i+1 << endl;
        cin >> x;
        p[i] = x - p[0];
    }
    cout << "! ";
    rep (i,0,n) cout << p[i] << ' ';
    cout<< endl;

}