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
  //  cin >> T;
    while (T--){
        int n,q,t = 0;
        cin >> n >> q;
        rep(i,0,n){
            cin >> a[i];
            t += a[i];
        }
        rep(i,0,q){
            int x,y;
            cin >> x >> y;
            if (x == 1){
                y--;
                if(a[y]) t--;
                else t++;
                a[y] = 1-a[y];
            }
            else{
                if (y <= t) cout << 1 << endl;
                else cout << 0 << endl;
            }
        }
    }
}