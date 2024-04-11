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
const long long int N = 1e5+20,mod = 1e9+7,inf = 1e18,sq = 400;
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
int ans[N],q1[N],q2[N];
int main(){
  //  ios :: sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        rep(i,1,n+1){
            ans[i] = -1;
            q1[i] = -1;
            q2[i] = -1;
        }
        int f2 = 0,f1 = 0;
        int ind0 = 0,ind1 = 0;
        for(int i = 1; i <= n; i += 3){
            cout << "? " << i << ' ' << i+1 << ' ' << i+2 << endl;
            cin >> q1[i];
            if (q1[i]){
                f1 = i;
            }
            else{
                f2 = i;
            }
        }
        int x,y,z,w;
        cout << "? " <<  f1 << ' ' << f2 << ' ' << f2+1 << endl;
        cin >> x;
        cout << "? " <<  f1 << ' ' << f2 << ' ' << f2+2 << endl;
        cin >> y;
        cout << "? " <<  f1+1 << ' ' << f2 << ' ' << f2+1 << endl;
        cin >> z;
        cout << "? " <<  f1+1 << ' ' << f2 << ' ' << f2+2 << endl;
        cin >> w;
        if (x || y){
            ans[f1] = 1;
            ind1 = f1;
            if (x && y){
                ans[f2] = 1;
                ans[f2+1] = 0;
                ans[f2+2] = 0;
                ind0 = f2+1;
            }
            else{
                ans[f2] = 0;
                ind0 = f2;
                ans[f2+2] = y;
                ans[f2+1] = x;
            }
        }
        if (z || w){
            ans[f1+1] = 1;
            ind1 = f1+1;
            if (w && z){
                ans[f2] = 1;
                ans[f2+1] = 0;
                ans[f2+2] = 0;
                ind0 = f2+1;
            }
            else{
                ans[f2] = 0;
                ind0 = f2;
                ans[f2+2] = w;
                ans[f2+1] = z;
            }
        }
        if (!x && !y && !z && !w){
            ans[f2] = 0;
            ans[f2+1] = 0;
            ans[f2+2] = 0;
            ind0 = f2;
            cout << "? " << f1  << ' ' << f1+1 << ' ' << f2 << endl;
            cin >> x;
            if (x){
                ans[f1] = 1;
                ans[f1+1] = 1;
                ind1 = f1;
            }
            else{
                cout << "? " << f1  << ' ' << f1+2 << ' ' << f2 << endl;
                cin >> y;
                if (y){
                    ans[f1] = 1;
                    ans[f1+2] = 1;
                    ind1 = f1;
                    ans[f1+1] = 0;
                }
                else{
                    ans[f1] = 0;
                    ans[f1+1] = 1;
                    ans[f1+2] = 1;
                    ind1 = f1+1;
                }
            }
        }
        vector<int> ve;
        rep(i,1,n+1){
            if (ans[i] == -1){
                cout << "? " << ind0 << ' ' << ind1 << ' ' << i << endl;
                cin >> x;
                ans[i] = x;
            }
            if (ans[i] == 0) ve.pb(i);
        }
        cout << "! " << ve.size() << ' ';
        for (int u : ve) cout << u << ' ';
        cout << endl;
    }
}