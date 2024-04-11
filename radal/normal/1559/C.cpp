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
typedef long long  int ll;
typedef pair<int,int> pll;
const long long int N=1e4+20,mod = 1e9+7,inf=8e18;
bool a[N];
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        rep(i,1,n+1) cin >> a[i];
        int p = 1;
        if (a[1]){
            cout << n+1 << ' ';
            rep(i,1,n+1) cout << i << ' ';
            cout << endl;
            continue;
        }
        vector<int> ve;
        bool f = 0;
        while (p < n+1){
            ve.pb(p);
            p++;
            if (a[p]){
                ve.pb(n+1);
                rep(i,p,n+1) ve.pb(i);
                f = 1;
                break;
            }
        }
        if (!f){
            rep(i,1,n+2) cout << i << ' ';
            cout << endl;
        }
        else{
            for (int u : ve) cout << u << ' ';
            cout << endl;
        }
    }
    return 0;
}