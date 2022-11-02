#include <bits/stdc++.h>
#pragma GCC target("sse,sse2")
#pragma GCC optimize("unroll-loops,O3")
#define rep(i,l,r) for (int i = l; i < r; i++)
#define repr(i,r,l) for (int i = r; i >= l; i--)
#define X first
#define Y second
#define all(x) (x).begin() , (x).end()
#define pb push_back
#define endl '\n'
#define debug(x) cerr << #x << " : " << x << endl;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pll;
constexpr int N = 1e5+20,mod = 1e9+7,inf = 1e9+10,base = 271;
inline int mkay(int a,int b){
    if (a+b >= mod) return a+b-mod;
    if (a+b < 0) return a+b+mod;
    return a+b;
}
 
inline int poww(int a,int k){
    if (k < 0) return 0;
    int z = 1;
    while (k){
        if (k&1) z = 1ll*z*a%mod;
        a = 1ll*a*a%mod;
        k /= 2;
    } 
    return z; 
}

int a[N],fen[N][2],n;
vector<int> ve;

void upd(int r,int x,bool f){
    for (; r < n; r |= (r+1))
        fen[r][f] += x;
}
int que(int r,bool f){
    int ans = 0;
    for (; r >= 0; r = (r&(r+1))-1)
        ans  += fen[r][f];
    return ans;
}
int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0);
    ll k;
    cin >> n >> k;
    rep(i,0,n){
        cin >> a[i];
        ve.pb(a[i]);
    }
    sort(all(ve));
    ll cur = 0;
    rep(i,0,n){
        a[i] = lower_bound(all(ve),a[i])-ve.begin();
        cur += i-que(a[i],0);
        upd(a[i],1,0);
    }
    if (cur <= k){
        cout << 1ll*n*(n-1)/2;
        return 0;
    }
    int l = n-1;
    while (l >= 0 && cur > k){
        cur -= (l+1-que(a[l],0));
        upd(a[l],-1,0);
        l--;
    }
    if (l == -1){
        cout << 0;
        return 0;
    }
    ll ans = 0;
    repr(i,n-2,1){
        upd(a[i+1],1,1);
        cur += que(a[i+1]-1,1);
        cur += l+1-que(a[i+1],0);
        while (l == i || (l >= 0 && cur > k)){
            upd(a[l],-1,0);
            cur -= (l-que(a[l],0));
            cur -= (que(a[l]-1,1));
            l--;
        }
        if (l == -1)
            break;
        ans += l+1;
    }
    cout << ans;
    return 0;
}