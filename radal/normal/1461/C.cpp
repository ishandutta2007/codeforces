#include <bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define ll long long int
#define endl '\n'
//#define mp make_pair
#define pb push_back
#define rep(i,l,r) for (ll i=l; i<r; i++)
#define repr(i,r,l) for (ll i=r; i>=l; i--)
using namespace std;
typedef pair<int,int> pll;
const long long int N=1e5+30,inf = 1e9;
long double p[N];
int a[N];
int main(){
    int T;
    cin >> T;
    while (T--){
        int n,m;
        cin >> n >> m;
        rep(i,0,n){
            cin >> a[i];
            p[i+1] = 0;
        }
        int ind = n-1;
        while (ind > -1 && a[ind] == ind+1) ind--;
        long double ans = 0,z = 1;
        rep(i,0,m){
            int x;
            long double y;
            cin >> x >> y;
            if (x >= ind+1){
                ans += z*y;
                z *= (1-y);
            }
        }
        if (ind == -1){
            cout << 1 << endl;
            continue;
        }
        z = 1;
        cout << fixed << setprecision(7) << min(z,ans) << endl;
    }
    return 0;
}