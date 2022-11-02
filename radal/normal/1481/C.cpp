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
typedef pair<ll,ll> pll;
const long long int N=1e5+20,mod = 1e9+7,inf=8e18,maxk = 1e5+20;
const long double eps = 0.0001;
int a[N],b[N],c[N],x[N];
vector<int> col[N];
int main(){
    int T;
    cin >> T;
    while (T--){
        int n,m;
        cin >> n >> m;
        rep(i,0,n){
            cin >> a[i];
            col[i+1].clear();
        }
        rep(i,0,n){
            cin >> b[i];
            if(b[i] != a[i]) col[b[i]].pb(i);
        }
        rep(i,0,m) cin >> c[i];
        int ind=-1;
        if (col[c[m-1]].size()){
            ind = col[c[m-1]].back()+1;
            col[c[m-1]].pop_back();
            a[ind-1] = c[m-1];
            x[m-1] = ind;
        }
        else{
            rep(i,0,n){
                if (b[i] == c[m-1]){
                    ind = i+1;
                    x[m-1] = i+1;
                    break;
                }
            }
        }
        if (ind == -1){
            cout << "NO" << endl;
            continue;
        }
        repr(i,m-2,0){
            if (col[c[i]].empty()){
                x[i] = x[i+1];
            }
            else{
                x[i] = col[c[i]].back()+1;
                a[x[i]-1] = c[i];
                col[c[i]].pop_back();
            }
        }
        bool f= 0;
        rep(i,0,n){
            if (b[i] != a[i]){
                f = 1;
                break;
            }
        }
        if (f){
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
        rep(i,0,m) cout << x[i] << ' ';
        cout << endl;
    }
    return 0;
}