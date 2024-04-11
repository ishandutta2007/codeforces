#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O2")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define endl '\n'
#define pb push_back
#define mp make_pair
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
typedef long long ll;
typedef pair<int,int> pll;
const long long int N=1e6+10,mod = 1e9+7,inf=1e18,dlt = 12251;
int poww(int n,int k){
    if (!k) return 1;
    if (k == 1) return n;
    ll r = poww(n,k/2);
    return (((r*r)%mod)*poww(n,k&1))%mod;
}
int main(){
    int T;
    cin >> T;
    while (T--){
        ll n;       
        cin >> n;
        if (n%2050){
            cout << -1 << endl;
            continue;
        }
        n /= 2050;
        ll sum = 0;
        while (n){
            sum += n%10;
            n /= 10;
        }
        cout << sum << endl;
    }
    return 0;
}