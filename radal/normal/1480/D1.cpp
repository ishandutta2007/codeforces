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
const long long int N=1e6+20,mod = 1e9+7,inf=8e18,maxk = 1e5+20;
const long double eps = 0.0001;
int a[N],b[N],fro[4];
int main(){
    int T=1;
    while (T--){
        int n;
        cin >> n;
        rep(i,0,n) cin >> a[i];
        fro[0] = a[0];
        fro[1] = -1;
        rep(i,1,n){
            if (a[i] == a[i-1]){
                b[i] = 1-b[i-1];
                fro[b[i]] = a[i];
            }
            else{
                if (i < n-1 && fro[1-b[i-1]] != a[i] && a[i+1] == fro[1-b[i-1]] && a[i+1] != fro[b[i-1]]){
                    b[i] = 1-b[i-1];
                    fro[b[i]] = a[i];
                }
                else{
                    b[i] = b[i-1];
                    fro[b[i]] = a[i];
                }

            }
        }
        vector <int> ve1,ve2;
        rep(i,0,n){
            if (b[i]) ve2.pb(a[i]);
            else ve1.pb(a[i]);
        }
        int cnt = 0,sz,sz2;
        sz = ve1.size();
        rep(i,0,sz){
            if (!i) cnt++;
            else if(ve1[i] != ve1[i-1]) cnt++;
        }
        sz2 = ve2.size();
        rep(i,0,sz2){
            if (!i) cnt++;
            else if (ve2[i] != ve2[i-1]) cnt++;
        }
        cout << cnt;
    }
    return 0;
}