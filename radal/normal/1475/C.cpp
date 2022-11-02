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
typedef long long  int ll;
typedef pair<ll,ll> pll;
const long long int N=2e5+20,mod = 1e9+7,inf=8e18,maxk = 1e5+20;
const long double eps = 0.0001;
ll cnt[N],cnt2[N];
int main(){
    int T;
    cin >> T;
    while (T--){
        ll a,b,k;
        cin >> a >> b >> k;
        rep(i,1,a+1) cnt[i] = 0;
        rep(j,1,b+1) cnt2[j] = 0;
        rep(i,0,k){
            int x;
            cin >> x;
            cnt[x]++;
        }
        rep(i,0,k){
            int x;
            cin >> x;
            cnt2[x]++;
        }
        ll sum = 0;
        rep(i,1,a+1) sum += cnt[i]*(cnt[i]-1)/2;
        rep(i,1,b+1) sum += cnt2[i]*(cnt2[i]-1)/2;
        cout << k*(k-1)/2-sum << endl;
    }
    return 0;
}