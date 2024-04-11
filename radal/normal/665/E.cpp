#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O8")
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
const long long int N=2e7+20,mod = 1e9+7,inf=1e18,dlt = 12250,maxm = 2e6;
int poww(ll a,int k){
    if (!k) return 1;
    if (k == 1) return a;
    ll r = poww(a,k/2);
    return (((r*r)%mod)*poww(a,k&1))%mod;
}
int trie[N][2],cnt,a[N],k;
int num[N];
void build(int v){
    int p = 0;
    num[p]++;
    repr(i,30,0){
        bool d = (v&(1 << i));
        if (!trie[p][d]){
            cnt++;
            trie[p][d] = cnt;
        }
        p = trie[p][d];
        num[p]++;
    }
}
ll qu(int x){
    int p = 0;
    ll ans = 0;
    repr(i,30,0){
        bool d = (k&(1 << i)),f = (x&(1 << i));

        if (!d){
            if (trie[p][!f]) ans += num[trie[p][!f]];
            p = trie[p][f];
        }
        else p = trie[p][!f];
        if (!p) return ans;
    }
    ans+=num[p];
    return ans;
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n >> k;
    build(0);
    int x = 0;
    ll ans = 0;
    rep(i,0,n) cin >> a[i];
    rep(i,0,n){
        x ^= a[i];
        ans+= qu(x);
        build(x);
    }
    cout << ans;
}