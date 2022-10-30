#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O3")
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
typedef long long  int ll;
typedef pair<ll,ll> pll;
const long long int N=1e6+30,mod = 1e9+7,inf=1e12;
ll a[N];
int main(){
    int T;
    cin >> T;
    while(T--){
        ll n,k,sum=0,ans=0;
        cin >> n >> k;
        rep(i,1,n*k+1){
            cin >> a[i];
        }
        ll p1=1,p2=n*k;
        rep(i,0,k){
            p2 -= n/2;
            ans += a[p2];
            p2--;
            p1 += (n)/2;
        }
        cout << ans << endl;

    }
}