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
typedef long long  int ll;
typedef pair<ll,ll> pll;
const long long int N=1020+20,mod = 1e9+7,inf=1e16;
const long double eps = 0.0001;
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        if (n == 1){
            cout << 9 << endl;
            continue;
        }
        if (n == 2){
            cout << 98 << endl;
            continue;
        }
        if (n == 3){
            cout << 989 << endl;
            continue;
        }
        cout << 989;
        rep(i,3,n){
            if (i%10 >= 3) cout<<(i%10)-3;
            if (i%10 == 0) cout << 7;
            if (i%10 == 1) cout << 8;
            if (i%10 == 2) cout << 9;
        }
        cout << endl;
    }
    return 0;
}