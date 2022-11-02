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
typedef long long ll;
typedef pair<int,int> pll;
const long long int N=1e6+10,mod = 1e9+7,inf=1e18,dlt = 12251;
ll poww(int a,int k){
    if (!k) return 1;
    if (k == 1) return a;
    ll r = poww(a,k/2);
    return (((r*r)%mod)*poww(a,k%2))%mod;
}
int pre[N];
int main(){
    ios :: sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--){
        int cnt = 0,n;
        string a,b;
        cin >> n >> a >> b;
        pre[0] = 0;
        if (a[0] == '0') pre[0]++;
        rep(i,1,n){
            pre[i] = pre[i-1];
            if (a[i] == '0') pre[i]++;
        }
        string ans = "YES";
        repr(i,n-1,0){
            if ((cnt%2 && a[i] != b[i]) || (cnt%2 == 0 && a[i] == b[i])) continue;
            if ((i+1)%2 || pre[i] != (i+1)/2) ans = "NO";
            else cnt++;
        }
        cout << ans << endl;
    }
    return 0;
}