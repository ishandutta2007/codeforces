#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O8")
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
const long long int N=1e5+10,mod = 1e9+7,inf=1e18,dlt = 12251;
ll poww(ll n,int k){
    if (!k) return 1;
    if (k == 1) return n;
    ll r = poww(n,k/2);
    return r*r*poww(n,k&1)%mod;
}
int main(){
    //ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,t,k,l = 1,r,m;
    cin >> n >> t >> k;
    r = n+1;
    while (r-l > 1){
        m = (l+r)/2;
        cout << "? 1 " << m << endl;
        int cnt;
        cin >> cnt;
        cnt = m-cnt;
        if (cnt >= k) r = m;
        else l = m;
    }
    cout << "? 1 " << l << endl;
    int cnt;
    cin >> cnt;
    cnt = l+1-cnt;
    if (cnt != k) cout << "! " << l << endl;
    else cout <<"! " <<  l+1 << endl;
    return 0;
}