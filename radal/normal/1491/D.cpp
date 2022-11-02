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
const int N = 5e3+20,mod = 1e9+7,inf = 2e9,sq = 800+10;
int a[N];
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T=1;
    cin >> T;
    while (T--){
        ll u,v;
        cin >> u >> v; 
        if (u > v){
            cout << "NO" << endl;
            continue;
        }
        int t=0,t2 = 0;
        bool f = 0;
        rep(i,0,30){
            if (u&(1ll << i)) t++;
            if (v&(1ll << i)) t2++;
            if (t2 > t){
                f = 1;
                break;
            }
        }
        cout << ((f) ? "NO" : "YES") << endl;
    }
}