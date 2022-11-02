#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O2")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define endl '\n'
#define pb push_back
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
typedef long long ll;
typedef pair<int,int> pll;
const long long int N=1e5+10,mod = 1e9+7,inf=1e18,dlt = 12251;
ll poww(int a,int k){
    if (!k) return 1;
    if (k == 1) return a;
    ll r = poww(a,k/2);
    return (((r*r)%mod)*poww(a,k%2))%mod;
}
int main(){
    int T;
    cin >> T;
    while (T--){
        int n,u1=0,u2=0,d1=0,d2=0;
        cin >> n;
        bool f1=0,f2=0;
        rep(i,0,n){
            int g;
            cin >> g;
            if (g == 1){
                u1++;
                continue;
            }
            if (g == 2) d1++;
            else u2++;
        }
        cout << u1+u2 << endl;
    }
    return 0;
}