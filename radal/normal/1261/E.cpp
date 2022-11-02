#include <bits/stdc++.h>
//#pragma GCC target("sse,sse2,avx2")
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
constexpr int N = 1e3+10,mod = 998244353,inf = 1e9+10;
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
bool op[N][N];
int a[N],mark[N],cont[N];
vector<int> ve,ve2;
int f(int d = 0){
    ve2.clear();
    int n = ve.size(),mi = inf,ind1 = -1,mx = 0;
    rep(i,0,n) if (a[ve[i]]){
        ve2.pb(ve[i]);
        mi = min(mi,a[ve[i]]);
        mx = max(mx,a[ve[i]]);
        if (a[ve[i]] == 1){
            ind1 = ve[i];
        }
    }
    if (ve2.empty()){
        cont[d] = 0;
        return 0; 
    }
    if ((int) ve2.size() < n){
        ve = ve2;
        return f(d);
    }
   /* if (mx == 1){
        for(int i : ve){
            a[ve[i]]--;
            cont[d]++;
            op[i][d] = 1;
        }
        return 1;
    }*/
    if (mi == 1){
        for (int i : ve){
            if (a[i] == 1 && i != ind1) continue;
            op[i][d] = 1;
            cont[d]++;
            a[i]--;
        }
        return 1+f(d+1);
    }
    memset(mark,-1,sizeof mark);
    int j = -1,k = -1;
    for (int i : ve){
        if (mark[a[i]] != -1){
            j = i;
            k = mark[a[i]];
            break;
        }
        mark[a[i]] = i;
    }
    ve2.clear();
    for (int i : ve){
        op[i][d] = 1;
        a[i]--;
        cont[d]++;
        if (i != j) ve2.pb(i);
    }
    ve = ve2;
    int cal = f(d+1);
    bool fj = 0,fk = 0;
    rep(i,d+1,cal+d+1){
        if (cont[i] == n-1){
            fk = 1;
            continue;
        }
    }
    rep(i,d+1,cal+d+1){
        if (cont[i] == n-1) continue;
        if (fk && !fj && !op[k][i]){
            fj = 1;
            op[j][i] = 1;
            a[j]--;
            cont[i]++;
            continue;
        }
        if (op[k][i]){
            op[j][i] = 1;
            a[j]--;
            cont[i]++;
        }
    }
    if (!fk || fj) return cal+1;
    op[j][d+cal+1] = 1;
    cont[d+cal+1]++;
    a[j]--;
    return cal+2;
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    rep(i,0,n){
        cin >> a[i];
        ve.pb(i);
    }
    int ans = f();
    cout << ans << endl;
    rep(i,0,ans){
        rep(j,0,n) cout << op[j][i];
        cout << endl;
    }
    return 0;
}