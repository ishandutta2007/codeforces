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
const int N = 3e5+20,mod = 1e9+7,inf = 2e9,sq = 800+10;
int poww(int a,int k){
    if (!k) return 1;
    if (k == 1) return a;
    int r = poww(a,k/2);
    return 1ll*r*r%mod*poww(a,k&1)%mod;
}
int a[N];
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T=1;
    cin >> T;
    while (T--){
        int n,u,v;
        cin >> n >> u >> v;
        rep(i,1,n+1)
            cin >> a[i];
        bool f = 0,f2 = 0;
        rep(i,2,n+1){
            if (abs(a[i]-a[i-1]) > 1){
                f = 1;
                break;
            }
            if (a[i] != a[i-1]) f2 = 1;
        }
        if (f){
            cout << 0 << endl;
            continue;
        }
        if (f2){
            cout << min(v,u) << endl;
            continue;
        }
        cout << v + min(v,u) << endl;

    }
}