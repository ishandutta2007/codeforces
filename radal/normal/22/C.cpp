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
#define rep(i,l,r) for (ll i=l; i<r; i++)
#define repr(i,r,l) for (ll i=r; i>=l; i--)
using namespace std;
const long long int N=2e5+30,mod = 998244353;
int main(){
    ll n,m,v;
    cin >> n >> m >> v;
    if (m > (n-1)*(n-2)/2+1 || m < n-1){
        cout << -1;
        return 0;
    }
    if (m == 0) return 0;
    if (v != 1){
        cout << 1 << ' ' << v << endl;
        m--;
        rep (i,2,n+1){
            rep (j,i+1,n+1){
                if (!m) break;
                cout << i << ' ' << j << endl;
                m--;
            }
            if (!m) break;
        }
    }
    else{
        cout << 1 << ' ' << 2 << endl;
        m--;
        rep (i,1,n+1){
            if (i == 2) continue;
            rep (j,i+1,n+1){
                if (j == 2) continue;
                if (!m) break;
                cout << i << ' '<<j << endl;
                m--;
            }
            if (!m) break;
        }
    }

}