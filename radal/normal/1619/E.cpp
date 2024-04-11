#include <bits/stdc++.h>
#pragma GCC optimize("O2")
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
typedef pair<int,int> pll;
const long long int N = 2e5+20,mod = 1e9+7,inf = 1e9,sq = 4e7;
inline int mkay(int a,int b){
    if (a+b >= mod) return a+b-mod;
    if (a+b < 0) return a+b+mod;
    return a+b;
}
inline int poww(int n,int k){
    int c = 1;
    while (k){
        if (k&1) c = (1ll*c*n)%mod;
        n = (1ll*n*n)%mod;
        k >>= 1;
    }
    return c;
}
int a[N],pre[N],cnt[N];
ll b[N];
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        rep(i,0,n+1) cnt[i] = 0;
        rep(i,0,n){
            cin >> a[i];
            cnt[a[i]]++;
        }
        pre[0] = cnt[0];
        b[0] = 0;
        rep(i,1,n+1){
            pre[i] = pre[i-1]+cnt[i];
            b[i] = b[i-1]+1ll*i*cnt[i];
        }
        sort(a,a+n);
        ll perv = 0;
        set<pll> st;
        rep(i,0,n+1){
            if (pre[i]-cnt[i] < i){
                rep(j,i,n+1){
                    cout << -1 << ' ';
                }
                break;
            }
            if (i == 0){
                cout << cnt[i] << ' ';
                perv = cnt[i];
            }
            else{
                if (cnt[i-1]){
                    cout << perv+cnt[i]-cnt[i-1] << ' ';
                    perv += cnt[i]-cnt[i-1];
                }
                else{
                    pll p = *(st.begin());
                    perv += i-1+p.X;
                    perv += cnt[i];
                    st.erase(p);
                    if (p.Y > 2) st.insert({p.X,p.Y-1});
                    cout << perv << ' ';
                }
            }
            if (cnt[i] >= 2) st.insert({-i,cnt[i]});
        }
        cout << endl;
    }
}