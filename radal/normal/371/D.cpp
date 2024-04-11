#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
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
const long long int N=2e5+20,mod = 1e9+7,inf=2e9;
const long double eps = 0.0000001;
int a[N],b[N],par[N];
int main(){
  //  ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    rep (i,0,n){
        cin >> a[i];
        par[i] = i+1;
    }
    int m;
    cin >> m;
    while (m--){
        int t;
        cin >> t;
        if (t == 1){
            int i,x;
            cin >> i >> x;
            i--;
            if (x <= a[i]-b[i]){
                b[i] += x;
                x = 0;
            }
            else{
                x -= (a[i]-b[i]);
                b[i] = a[i];
            }
            int cu = i;
            while (par[cu] && x){
                if (a[par[cu]] == b[par[cu]]) par[cu] = par[par[cu]];
                if (!par[cu]) break;
                if (x <= a[par[cu]]-b[par[cu]]){
                    b[par[cu]] += x;
                    x = 0;
                }
                else{
                    x -= (a[par[cu]]-b[par[cu]]);
                    b[par[cu]] = a[par[cu]];
                }
                cu = par[cu];
            }
        }
        if (t == 2){
            int k;
            cin >> k;
            cout << b[k-1] << endl;
        }
    }
    return 0;
}