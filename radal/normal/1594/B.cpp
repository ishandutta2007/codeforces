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
const int N = 1e5+20,mod = 1e9+7,inf = 2e9,sq = 400;
bool a[N];
int poww(int n,int k){
    if (!k) return 1;
    if (k == 1) return n;
    int r = poww(n,k/2);
    return 1ll*r*r%mod*poww(n,k&1)%mod;
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--){
        int n,k;
        cin >> n >> k;
        int cnt = 1,j = 0;
        rep(i,1,35){
            if (cnt >= k) break;
            cnt += (1 << i);
            j = i;
        }
        a[j] = 1;
        k -= (1 << j);
        int p = j;
        while (j){
            j--;
            if (k >= (1 << j)){
                a[j] = 1;
                k -= (1 << j);
            }
            else a[j] = 0;
        }
        int ans = 0;
        rep(i,0,p+1){
            if (!a[i]) continue;
            ans += poww(n,i);
            ans %= mod;
        }
        cout << ans << endl;
    }
}