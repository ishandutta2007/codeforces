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
int a[N];
void binary(int n){
    int l = 1,r = n+1,m;
    while (r-l > 1){
        m = (l+r)/2;
        if (a[m] == -1){
            cout << "? " << m << endl;
            cin >> a[m];
        }
        if (m != 1 && a[m-1] == -1){
            cout << "? " << m-1 << endl;
            cin >> a[m-1];
        }
        if (m != n && a[m+1] == -1){
            cout << "? " << m+1 << endl;
            cin >> a[m+1];
        }
        if (m == 1 && a[m] < a[m+1]){
            cout << "! "  << 1 << endl;
            return;
        }
        if (m == n && a[m] < a[m-1]){
            cout << "! " << n << endl;
            return;
        }
        if (a[m] < a[m+1] && a[m] < a[m-1]){
            cout <<"! " << m << endl;
            return;
        }
        if (a[m+1] > a[m-1]) r = m;
        else l = m;
    }
    cout << "! " << l << endl;
    return;
}
int main(){
    int T=1;
    while (T--){
        memset(a,-1,sizeof a);
        int n;
        cin >> n;
        if (n == 1){
            cout << "! " << 1 << endl;
            return 0;
        }
        if (n == 2){
            cout << "? " << 1 << endl;
            cin >> a[1];
            cout << "! ";
            if (a[1] == 1) cout << 1 << endl;
            else cout << 2 << endl;
            return 0;
        }
        binary(n);
    }
    return 0;
}