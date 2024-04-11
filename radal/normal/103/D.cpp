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
const int N = 6e5+20,mod = 1e9+7,inf = 2e9,sq = 50+10;
int w[N];
pair<pll,int> que[N];
ll ans[N],dp[N];
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,q;
    cin >> n;
    rep(i,1,n+1) cin >> w[i];
    cin >> q;
    rep(i,0,q){
        cin >> que[i].X.Y >> que[i].X.X;
        que[i].Y = i;
    }
    sort(que,que+q); 
    int prev = -1;
    rep(i,0,q){
        int a = que[i].X.Y,b = que[i].X.X;
        if (prev == b){
            ans[que[i].Y] = dp[a];
            continue;
        }
        if (b > 500){
            prev = -1;
            while (a <= n){
                ans[que[i].Y] += w[a];
                a += b;
            }
            continue;
        }
        prev = b;
        repr(i,n,1)
            dp[i] = w[i]+dp[i+b];
        ans[que[i].Y] = dp[a];
    }
    rep(i,0,q) cout << ans[i] << endl;
}