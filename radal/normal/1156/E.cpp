#include <bits/stdc++.h>
//#pragma GCC target("sse,sse2,avx2")
#pragma GCC optimize("unroll-loops,O2")
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
constexpr int N = 3e5+20,mod = 1e9+7,inf = 1e9+10,base = 271;
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
int a[N],ind[N],l[N],r[N];
int n;
bool b[N];
int getpar(int i){
    if (i == l[i]) return i;
    return l[i] = getpar(l[i]);
}
int getpar2(int i){
    if (i == r[i]) return i;
    return r[i] = getpar2(r[i]);
}
int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0);
    cin >> n;
    rep(i,0,n){
        cin >> a[i];
        ind[a[i]] = i;
        l[i] = i;
        r[i] = i;
    }
    ll ans = 0;
    rep(i,1,n+1){
        int j = ind[i],l1,l2;
        if (!j || !b[j-1]) l1 = 0;
        else{
            getpar(j-1);
            l1 = j-l[j-1];
            l[j] = l[j-1];
        }
        if (j == n-1 || !b[j+1]) l2 = 0;
        else{
            getpar2(j+1);
            l2 = r[j+1]-j;
            r[j] = r[j+1];
        }
        if (l1 <= l2){
            rep(k,j-l1,j){
                if (ind[i-a[k]] > j && ind[i-a[k]] <= j+l2) ans++;
            }
        }
        else{
            rep(k,j+1,j+l2+1){
                if (ind[i-a[k]] < j && ind[i-a[k]] >= j-l1) ans++;
            }
        }
        b[j] = 1;
        if (j < n-1 && b[j+1]) l[j+1] = l[j];
        if (j && b[j-1]) r[j-1] = r[j];
    }
    cout << ans;
    return 0;
}