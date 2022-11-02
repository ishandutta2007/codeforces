#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O8")
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
const long long int N=3e5+10,mod = 1e9+7,inf=1e18,dlt = 12251;
ll poww(ll n,int k){
    if (!k) return 1;
    if (k == 1) return n;
    ll r = poww(n,k/2);
    return r*r*poww(n,k&1);
}
int a[N];
int main(){
    int T;
    cin >> T;
    while (T--){
        int n,x;
        cin >> n >> x;
        int s = 0;
        rep(i,0,n){
            cin >> a[i];
            s += a[i];
        }
        cout << ((s != x) ? "YES" : "NO") << endl;
        if (s != x){
            s = 0;
            rep(i,0,n){
                s+=a[i];
                if (s != x) cout << a[i] << ' ';
                else{
                    s+= a[i+1];
                    cout << a[i+1] << ' ' << a[i] << ' ';
                    i++;
                }
            }
            cout << endl;
        }
        
    }
}