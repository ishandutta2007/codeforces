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
int a[N],lz[N];
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T=1;
    cin >> T;
    while (T--){
        int n;
        ll ans = 0;
        cin >> n;
        rep(i,1,n+1){
            cin >> a[i];
            lz[i] = 0;
        }
        int p =  1;
        while (p <= n){
            while (lz[p]){
                if (a[p] == 1){
                    lz[p+1] += lz[p];
                    lz[p] = 0;
                }
                else{
                    if (p+a[p] > n){
                        lz[p]--;
                        a[p]--;
                    }
                    else{
                        lz[p+a[p]]++;
                        lz[p]--;
                        a[p]--;
                    }
                }
            }
            if (a[p] == 1){
                p++;
                continue;
            }
            if (p == n){
                ans += a[p]-1;
                break;
            }
            if (a[p]+p > n){
                ans += a[p]+p-n;
                a[p] = n-p;
            }
            while (a[p] > 1){
                lz[p+a[p]]++;
                a[p]--;
                ans++;
            }
            p++;
        }
        cout << ans << endl;
    }
}