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
const long long int N=1e5+20,mod = 1e9+7,inf=2e18,dlt = 12250,maxm = 3e5+20;
ll poww(int n,int k){
    if (!k) return 1;
    if (k == 1) return n;
    ll r = poww(n,k/2);
    return (r*r)%mod*poww(n,k&1)%mod;
}
int l[N],r[N];
int main(){
    int T;
    cin >> T;
    while (T--){
        int n,m;
        string s;
        cin >> n >> m;
        cin >> s;
        l[0] = 2e9;
        if (s[0] == '1') l[0] = 0;
        rep(i,1,n){
            if (s[i] == '1') l[i] = 0;
            else l[i] = l[i-1]+1;
        }
        r[n-1] = 0;
        if (s[n-1] == '0') r[n-1] = 2e9;
        repr(i,n-2,0){
            if (s[i] == '0') r[i] = r[i+1]+1;
            else r[i] = 0;
        }
        rep(i,0,n){
            if (s[i] == '1') cout << 1;
            else{
                if (r[i] == l[i] || min(l[i],r[i]) > m) cout << 0;
                else cout << 1;
            }
        }
        cout << endl;
    }
    return 0;
}