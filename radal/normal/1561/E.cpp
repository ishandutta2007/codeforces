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
const long long int N=3e3+20,mod = 1e9+7,inf=1e9;
int a[N],ind[N];
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--){
        int n;
        bool f = 1;
        cin >> n;
        rep(i,1,n+1){
            cin >> a[i];
            ind[a[i]] = i;
            if ((a[i]&1) != (i&1)) f = 0;
        }
        if (!f){
            cout << -1 << endl;
            continue;
        }
        int p = n;
        vector<int> ans;
        while (p > 1){
            int x = ind[p],y = ind[p-1];
            if (x < y){
                ans.pb(x);
                ans.pb(y-1);
                reverse(a+1,a+x+1);
                reverse(a+1,a+y);
            }
            else{
                ans.pb(x);
                reverse(a+1,a+x+1);
                rep(i,1,x+1) ind[a[i]] = i;
                ans.pb(ind[p-1]-1);
                reverse(a+1,a+ind[p-1]);
            }
            rep(i,1,n+1) ind[a[i]] = i;
            x = ind[p],y = ind[p-1];
            ans.pb(y+1);
            reverse(a+1,a+y+2);
            ans.pb(3);
            reverse(a+1,a+4);
            ans.pb(p);
            reverse(a+1,a+p+1);
            rep(i,1,n+1) ind[a[i]] = i;
            p -= 2;
        }
        cout << ans.size() << endl;
        for (int u : ans) cout <<  u << ' ';
        cout << endl;
    }
}