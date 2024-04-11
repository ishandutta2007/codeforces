#include <bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("Ofast")
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
const long long int N=1e6+30,mod = 1e9+7,inf=1e18;
ll a[N];
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    ll T;
    cin >> T;
    while (T--){
        ll n;
        cin >> n;
        bool f=0,f2=1;
        rep (i,0,n) {
            cin >> a[i];
            if (i && a[i] == a[i-1]) a[i]++;
        }
        rep  (i,0,n){
            if (i && a[i] > a[i-1]){
                cout << "YES" << endl;
                f=1;
                break;
            }
            if (i && a[i] != a[i-1]) f2=0;
        }
        if (f2 && !f){
            cout << "YES" << endl;
            continue;
        }
        if (!f){
            cout << "NO" << endl;
        }
    }
    return 0;
}