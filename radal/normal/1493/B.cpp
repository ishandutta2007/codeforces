#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O8")
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
const long long int N=2e6+20,mod = 1e6+3,inf=4e18,maxm = 2e5+20;
const long double eps = 0.0001;
ll poww(ll n,int k){
    if (k == 1) return n;
    ll r = poww(n,k/2);
    ll ans;
    if (k%2 == 0) ans = (r*r)%mod;
    else ans = (n*r*r)%mod;
    return ans;
}
bool val(char c){
    return (c == '1' || c == '0' || c == '2' || c== '8' || c == '5');
}
int rev(int c){
    if (c == 2) return 5;
    if (c == 5) return 2;
    return c;
}
int main(){
    int t;
    cin >> t;
    while (t--){
        int h,m,h2,m2;
        string s;
        cin >> h >> m;
        cin >> s;
        h2 = (s[0]-'0')*10+(s[1]-'0');
        m2 = (s[3]-'0')*10+(s[4]-'0');
        if (val(char('0'+h2/10)) && val(char('0'+h2%10)) && rev(h2/10)+rev(h2%10)*10 < m){
            int x,y;
            bool f = 0;
            rep(i,0,101){
                x = (i+m2)%m;
                int c,d;
                if (i && x == 0){
                    f = 1;
                    h2++;
                    h2 %= h;
                    int y;
                    rep(j,0,101){
                        y = (h2+j)%h;
                        int c,d;
                        if (val(char(y/10+'0')) && val(char(y%10+'0'))){
                            c = rev(y/10);
                            d = rev(y%10);
                            if (d*10+c < m) break;
                        }
                    }
                    if (y < 10) cout << 0;
                    cout << y << ":00" << endl;
                    break;
                }
                if (val(char(x/10+'0')) && val(char(x%10+'0'))){
                    c = rev(x/10);
                    d = rev(x%10);
                    if (d*10+c < h) break;
                }
            }
            if (f) continue;
            if (h2 < 10) cout << 0;
            cout << h2 << ':';
            if (x < 10) cout << 0;
            cout << x << endl;
            continue;
        }
        int y;
        rep(i,0,101){
            y = (h2+i)%h;
            int c,d;
            if (val(char(y/10+'0')) && val(char(y%10+'0'))){
                c = rev(y/10);
                d = rev(y%10);
                if (d*10+c < m) break;
            }
        }
        if (y < 10) cout << 0;
        cout << y << ":00" << endl;
    }
    return 0;
}