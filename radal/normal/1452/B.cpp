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

typedef long long int ll;
typedef pair<ll,ll> pll;
const long long int N=2e5+30,mod = 1e9+7,inf=1e9;
ll a[N],b[N],pre[N];
multiset <int> st;
ll n,sum;
bool check(int x){
    if ((x+sum)%(n-1)) return 0;
    ll goal = (sum +x)/(n-1);
    if (a[n-1] > goal) return 0;
    ll ans = 0,ind=0;
    ll s = 0;
    ans = min(a[0]+x,a[1]);
    pre[0] = a[0];
    rep(i,1,n){
        if (a[i]*(i)-pre[i-1] > x) break;
        if (i < n-1 && ans < min(a[i+1],a[i]+(x-a[i]*i+pre[i-1])/(i+1))){
            ans = min(a[i+1],a[i]+(x-a[i]*i+pre[i-1])/(i+1));
            ind = i;
        }
        else if (ans < a[i]+(x-a[i]*i+pre[i-1])/(i+1)){
            ans = a[i]+(x-a[i]*i+pre[i-1])/(i+1);
            ind  = i;
        }
        pre[i] = a[i]+pre[i-1];
    }
    //debug(ans);
    s = 0;
    rep(i,0,ind+1){
        b[i] = a[ind]+(x-a[ind]*ind+pre[ind])/(ind+1);
        s+= b[i];
        x = x-a[ind]*ind+pre[ind];
    }
    rep(i,ind+1,n){
        b[i] = a[i];
        s+=b[i];
    }
    int r = (x)%(ind+1);
    repr(i,ind,ind-r+1){
        b[i]++;
        s++;
    }
    return ans >= goal*(n-1)-s;
}
ll binary(ll l , ll r,int val){
    ll m;
    rep(i,0,500){
        ll m = (r+l)/(2*n-2);
        if ( m > r) break;
        if (check(m+val)) r = m;
        else l = m;
    }
    return l;
}
int main(){
    ios :: sync_with_stdio(); cout.tie();
    int T;
    cin >> T;
    while (T--){
        sum = 0;
        cin >> n;
        rep(i,0,n){
            cin >> a[i];
            sum += a[i];
        }
        sort(a,a+n);
        if (sum <= (n-1)*a[n-1]){
            cout << (n-1) * a[n-1]-sum << endl;
            continue;
        }
        if (sum%(n-1)) cout << (sum/(n-1)+1)*(n-1)-sum << endl;
        else cout << 0 << endl;

    }
}