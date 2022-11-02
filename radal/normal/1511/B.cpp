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
    int l[18] = {2,3,11,13,101,103,1009,1013,10009,10037,104677,104681,1003001,1008001,99999997,15485863,999999937,100030001};
    while (T--){
        ll a,b,c;
        cin >> a >> b >> c;
        ll x,y,z;
        z = poww(10,c-1);
        x = z*l[(a-c)*2];
        if (b == a) y = z*l[(a-c)*2+1];
        else y = z*l[(b-c)*2];
        cout << x << ' ' << y << endl;

    }
    return 0;
}