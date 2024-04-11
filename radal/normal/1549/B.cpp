#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O3")
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
typedef pair<ll,int> pll;
const long long int N=2e5+20,mod = 1e9+7,inf=1e18,maxm = (1 << 18);
int poww(ll a,int k){
    if (!k) return 1;
    if (k == 1) return a;
    ll r = poww(a,k/2);
    return (((r*r)%mod)*poww(a,k&1))%mod;
}
bool mark[N];
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T=1;
    cin >> T;
    while (T--){
        int n,ans = 0;;
        string s,t;
        cin >> n;
        cin >> s;
        cin >> t;
        rep(i,0,n){
            if (t[i] == '0') continue;
            if (s[i] == '0') ans++;
            else{
                if (i && s[i-1] == '1' && !mark[i-1]){
                    ans++;
                    continue;
                }
                if (i < n-1 && s[i+1] == '1'){
                    ans++;
                    mark[i+1] = 1;
                }
            }
        }
        rep(i,0,n) mark[i] = 0;
        cout << ans << endl;
    }
    return 0;
}