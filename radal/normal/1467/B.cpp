#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O2")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define endl '\n'
#define pb push_back
#define rep(i,l,r) for (ll i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
typedef long long  int ll;
typedef pair<ll,ll> pll;
const long long int N=3e5+20,mod = 1e9+7,inf=2e9;
const long double eps = 0.0001;
int a[N];
int n;
inline bool h(int i){
    if (!i || i == n-1) return 0;
    return (a[i] > a[i-1] && a[i] > a[i+1]);
}
inline bool v(int i){
    if (!i || i == n-1) return 0;
    return (a[i] < a[i-1] && a[i] < a[i+1]);
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    bool f = (T ==  10000);
    while (T--){
        cin >> n;
        rep(i,0,n) cin >> a[i];
        if (n < 3){
            cout << 0 << endl;
            continue;
        }
        int val=0,hil=0;
        bool dou = 0,trio = 0;
        rep(i,1,n-1){
            if (h(i)) hil++;
            if (v(i)) val++;
            int x = a[i];
            int cnt = v(i-1)+v(i+1)+h(i-1)+h(i+1)+v(i)+h(i);
            a[i] = max(a[i-1],a[i+1]);
            if (v(i)+h(i)+v(i-1) + v(i+1)+h(i-1)+h(i+1) == cnt-3) trio = 1;
            if (v(i)+h(i)+v(i-1)+v(i+1)+h(i-1)+h(i+1) == cnt-2) dou = 1,debug(i);
            a[i] = min(a[i-1],a[i+1]);
            if (v(i)+h(i)+v(i-1) + v(i+1)+h(i+1)+h(i-1) == cnt-3) trio = 1;
            if (v(i)+h(i)+v(i-1)+v(i+1)+h(i-1)+h(i+1) == cnt-2) dou = 1;
            a[i] = (a[i-1]+a[i+1])/2;
            if (v(i)+h(i)+v(i-1) + v(i+1)+h(i+1)+h(i-1) == cnt-3) trio = 1;
            if (v(i)+h(i)+v(i-1)+v(i+1)+h(i-1)+h(i+1) == cnt-2) dou = 1;
            a[i] = max(a[i-1],a[i+1])+1;
            if (v(i)+h(i)+v(i-1) + v(i+1)+h(i-1)+h(i+1) == cnt-3) trio = 1;
            if (v(i)+h(i)+v(i-1)+v(i+1)+h(i-1)+h(i+1) == cnt-2) dou = 1;
            a[i] = min(a[i-1],a[i+1])-1;
            if (v(i)+h(i)+v(i-1) + v(i+1)+h(i+1)+h(i-1) == cnt-3) trio = 1;
            if (v(i)+h(i)+v(i-1)+v(i+1)+h(i-1)+h(i+1) == cnt-2) dou = 1;
            a[i] = a[i+1]-1;
            if (v(i)+h(i)+v(i-1) + v(i+1)+h(i-1)+h(i+1) == cnt-3) trio = 1;
            if (v(i)+h(i)+v(i-1)+v(i+1)+h(i-1)+h(i+1) == cnt-2) dou = 1;
            a[i] = a[i+1]+1;
            if (v(i)+h(i)+v(i-1) + v(i+1)+h(i+1)+h(i-1) == cnt-3) trio = 1;
            if (v(i)+h(i)+v(i-1)+v(i+1)+h(i-1)+h(i+1) == cnt-2) dou = 1;
            a[i] = a[i-1]+1;
            if (h(i)+v(i)+v(i-1) + v(i+1)+h(i-1)+h(i+1) == cnt-3) trio = 1;
            if (h(i)+v(i)+v(i-1)+v(i+1)+h(i-1)+h(i+1) == cnt-2) dou = 1;
            a[i] = a[i-1]-1;
            if (h(i)+v(i)+v(i-1) + v(i+1)+h(i+1)+h(i-1) == cnt-3) trio = 1;
            if (h(i)+v(i)+v(i-1)+v(i+1)+h(i-1)+h(i+1) == cnt-2) dou = 1;
            a[i] = x;
        }
        if (hil+val == 0) cout << 0 << endl;
        else {
            if (trio){
                cout << max(0,hil+val-3) << endl;
                continue;
            }
            if (dou){
                cout << max(0,hil+val-2) << endl;
                continue;
            }
            cout << hil+val-1 << endl;
        }
    }
    return 0;
}