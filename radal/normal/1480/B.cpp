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
pll m[N];
int main(){
    int T;
    cin >> T;
    while (T--){
        ll a,b,n;
        cin >> a >> b >> n;
        ll sum = 0;
        rep(i,0,n) cin >> m[i].X;
        rep(i,0,n) cin >> m[i].Y;
        int i = 0;
        sort(m,m+n);
        while (i < n && b > 0){
            int cnt1,cnt2;
            cnt1 = b/m[i].X;
            if (b%m[i].X) cnt1++;
            cnt2 = m[i].Y/a;
            if (m[i].Y%a) cnt2++;
            if (cnt2 > cnt1) break;
            if (cnt1 == cnt2){
                b = 0;
                m[i].Y = 0;
                break;
            }
            m[i].Y = 0;
            b -= m[i].X*cnt2;
            i++;
        }
        bool f = 1;
        rep(i,0,n) if (m[i].Y > 0) f = 0;
        (f) ?  cout << "YES" << endl : cout << "NO" << endl;
    }
    return 0;
}