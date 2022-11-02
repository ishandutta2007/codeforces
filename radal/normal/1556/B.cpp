#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimize ("O2")
#pragma GCC optimize ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define endl '\n'
#define pb push_back
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
typedef long long ll;
typedef pair<int,int> pll;
const long long int N=1e5+20,mod = 1e9+7,inf=1e9,maxm = 1e6+1;
int a[N],b[N];
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        int o = 0,e = 0;
        vector<int> ve1,ve2;
        rep(i,0,n){
            cin >> a[i];
            a[i] &= 1;
            b[i] = a[i];
            if (a[i]){
                o++;
                ve1.pb(i);
            }
            else{
                e++;
                ve2.pb(i);
            }
        }
        if (max(e,o) > (n+1)/2){
            cout << -1 << endl;
            continue;
        }
        ll ans = 0;
        if (e == o || e > o){
            rep(i,0,o){
                ans += abs(ve1[i]-2*i-1);
            }
            if (e > o){
                cout << ans << endl;
                continue;
            }
        }
        ll ans2 = 0;
        rep(i,0,e)
            ans2 += abs(ve2[i]-2*i-1);
        if (o > e) cout << ans2 << endl;
        else cout << min(ans,ans2) << endl;
    }
    return 0;
}