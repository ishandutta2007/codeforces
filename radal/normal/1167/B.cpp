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
    ll a[6];
    rep (i,0,2){
        ll n,m,x,y,z;
        cout << "? " << 3*i+1 << ' ' << 3*i+2 << endl;
        cin >> n;
        cout << "? " << 3*i+2 << ' ' << 3*i+3 << endl;
        cin >> m;
        if (n == 4*8){
            x = 4;
            y = 8;
        }
        if (n == 4*15){
            x = 4;
            y = 15;
        }
        if (n == 4*16){
            x = 4;
            y = 16;
        }
        if (n == 4*23){
            x = 4;
            y = 23;
        }
        if (n == 4*42){
            x = 4;
            y = 42;
        }
        if (n == 15*8){
            x = 8;
            y = 15;
        }
        if (n == 16*8){
            x = 16;
            y = 8;
        }
        if (n == 23*8){
            x = 23;
            y = 8;
        }
        if (n == 42*8){
            x = 42;
            y = 8;
        }
        if (n == 15*16){
            x = 16;
            y = 15;
        }
        if (n == 15*23){
            x = 15;
            y = 23;
        }
        if (n == 42*15){
            x = 42;
            y = 15;
        }
        if (n == 16*23){
            x = 16;
            y = 23;
        }
        if (n == 42*16){
            x = 42;
            y = 16;
        }
        if (n == 23*42){
            x = 42;
            y = 23;
        }
        if (m % x){
            a[3*i+1] = y;
            a[3*i] = x;
            a[3*i+2] = m/y;
            continue;
        }
        if (m % y){
            a[3*i+1] = x;
            a[3*i] = y;
            a[3*i+2] = m/x;
            continue;
        }
        z = m/x;
        if (z == 4 || z == 8 || z == 15 || z == 16 || z == 23 || z == 42){
            a[3*i+1] = x;
            a[3*i] = y;
            a[3*i+2] = z;
        }
        else{
            a[3*i+1] = y;
            a[3*i] = x;
            a[3*i+2] = m/y;
        }
    }
    cout << "! ";
    rep (i,0,6) cout << a[i] << ' ';
    cout << endl;
    return 0;
}