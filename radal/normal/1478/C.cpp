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
const long long int N=2e5+20,mod = 1e9+7,inf=8e18,maxk = 1e5+20;
const long double eps = 0.0001;
ll a[N],b[N];
ll pre[N];
int main(){
    int T;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        bool f = 1;
        rep(i,0,2*n){
            cin >> a[i];
            if (a[i]%2) f = 0;
        }
        sort(a,a+2*n);
        for (int i = 0; i < 2*n-1; i+=2){
            if (a[i] != a[i+1]) f = 0;
            if ((i < 2*n-2 && a[i] == a[i+2]) || (i && a[i] == a[i-1])) f = 0;
        }
        if (!f || a[2*n-2]%(2*n)){
            cout << "NO" << endl;
            continue;
        }
        b[2*n-2] = a[2*n-2]/(2*n);
        pre[2*n-2] = 2*abs(b[2*n-2]);
        if (!b[2*n-2]) f = 0;
        for (int i = 2*n-4; i >= 0; i-=2){
            if ((a[i]-pre[i+2])%(i+2)){
                f = 0;
                break;
            }
            b[i] = (a[i]-pre[i+2])/(i+2);
            pre[i] = pre[i+2]+2*abs(b[i]);
            if (!b[i]) f = 0;
            if ((i+2)*abs(b[i])+pre[i+2] != a[i]) f = 0;
        }
        if (!f) cout << "NO" << endl;
        else cout << "YES"<< endl;
    }
    return 0;

}