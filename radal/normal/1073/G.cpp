#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("avx2,fma")
#define rep(i,l,r) for (int i = l; i < r; i++)
#define repr(i,r,l) for (int i = r; i >= l; i--)
#define X first
#define Y second
#define pb push_back
#define endl '\n'
#define debug(x) cerr << #x << " : " << x << endl;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pll;
const long long int N = 4e5+20,mod = 2e9+33,mod2 = 1e9+7,inf = 1e18+10,maxm= (1 << 21);
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
        k >>= 1;
    }
    return z;
}
string s;
int n,pw[N],a[N],ind[N],l[N];
int hsh[N];
vector<int> suf;
inline int bs(int i,int j){
    int l = -1,r = n-max(i,j),m;
    while (r-l > 1){
        m = (l+r) >> 1;
        int g1,g2;
        g1 = hsh[i+m];
        g2 = hsh[j+m];
        if (i){
            g1 -= 1ll*hsh[i-1]*pw[m+1]%mod;
            if(g1 < 0) g1 += mod;
        }
        if (j){
            g2 -= 1ll*hsh[j-1]*pw[m+1]%mod;
            if (g2 < 0) g2 += mod;
        }
        if (g1 == g2) l = m;
        else r = m;
    }
    return r;
}
inline bool cmp(int i,int j){
    int x = bs(i,j);
    if (max(i,j)+x >= n)
        return (i > j);
    return (s[i+x] < s[j+x]);
}
inline bool cmp2(pll i,pll j){
    if (ind[i.Y] != ind[j.Y])
        return (ind[i.Y] < ind[j.Y]);
    return (i.X < j.X);
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int q;
    cin >> n >> q;
    cin >> s;
    pw[0] = 1;
    rep(i,0,n){
        pw[i+1] = 1ll*pw[i]*359%mod;
        suf.pb(i);
        hsh[i] = s[i]-'a'+1;
        if (i){
            hsh[i] = (hsh[i]+1ll*hsh[i-1]*359%mod)%mod;
        }
    }
    sort(suf.begin(),suf.end(),cmp);
    rep(i,0,n) ind[suf[i]] = i;
    while (q--){
        int x,y;
        vector<pair<bool,int> > v1;
        map<int,int> mp;
        cin >> x >> y;
        rep(i,0,x){
            int v;
            cin >> v;
            v--;
            v1.pb({1,v});
        }
        rep(i,0,y){
            int v;
            cin >> v;
            v--;
            v1.pb({0,v});
        }
        sort(v1.begin(),v1.end(),cmp2);
        rep(i,1,x+y)
            a[i] = bs(v1[i].Y,v1[i-1].Y);
        ll ans = 0,sum = 0;
        rep(i,0,x+y){
            if (v1[i].X == 1){
                mp[n-v1[i].Y]++;
                sum += n-v1[i].Y;
            }
            else
                ans += sum;
            if (i < x+y-1){
                while (!mp.empty()){
                    auto it = mp.end();
                    it--;
                    if (it -> X <= a[i+1]) break;
                    sum -= 1ll*(it->Y)*(it->X);
                    mp[a[i+1]] += it->Y;
                    sum += 1ll*a[i+1]*(it->Y);
                    mp.erase(it);
                }
            }
        }
        mp.clear();
        sum = 0;
        repr(i,x+y-1,0){
            if (v1[i].X == 1){
                mp[n-v1[i].Y]++;
                sum += n-v1[i].Y;
            }
            else{
                ans += sum;
            }
            if (i){
                while (!mp.empty()){
                    auto it = mp.end();
                    it--;
                    if (it -> X <= a[i]) break;
                    sum -= 1ll*(it->Y)*(it->X);
                    mp[a[i]] += it->Y;
                    sum += 1ll*a[i]*(it->Y);
                    mp.erase(it);
                }
            }
        }
        cout << ans << endl;
    }
 }