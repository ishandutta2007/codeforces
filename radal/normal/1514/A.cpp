#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O2")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define endl '\n'
#define pb push_back
#define mp make_pair
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
typedef long long ll;
typedef pair<int,int> pll;
const long long int N=2e5+10,mod = 1e9+7,inf=1e18,dlt = 12251;
ll a[N],b[N],c[N],d[N];
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        int n;
        cin>> n;
        rep(i,0,n) cin >> a[i];
        bool f = 0;
        rep(i,0,n){
            int s = sqrt(a[i]);
            if (s*s != a[i]) f = 1;
        }
        cout << ((f) ? "YES" : "NO") << endl;
    }
}