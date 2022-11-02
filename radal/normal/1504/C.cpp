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
typedef long long ll;
typedef pair<int,int> pll;
const long long int N=1e6+10,mod = 1e9+7,inf=1e18,dlt = 12251;
ll poww(int a,int k){
    if (!k) return 1;
    if (k == 1) return a;
    ll r = poww(a,k/2);
    return (((r*r)%mod)*poww(a,k%2))%mod;
}
int pre[N];
int main(){
    ios :: sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--){
        string s,x,y;
        int n;
        cin >> n >> s;
        int cnt=0;
        rep(i,0,n){
            if (s[i] == '1') cnt++;
            x += '1';
            y += '2';
        }
        if (s[0] == '0' || cnt%2){
            cout << "NO" << endl;
            continue;
        }
        int k = 0;
        rep(i,0,n){
            if (s[i] == '0') continue;
            if (k < cnt/2){
                x[i] = '(';
                y[i] = '(';
            }
            else{
                x[i] = ')';
                y[i] = ')';
            }
            k++;
        }
        bool f = 0;
        rep(i,0,n){
            if (s[i] == '1') continue;
            if (!f){
                x[i] = '(';
                y[i] = ')';
            }
            else{
                x[i] = ')';
                y[i] = '(';
            }
            f = 1-f;
        }
        f = 0;
        cnt = 0;
        k = 0;
        rep(i,0,n){
            if (x[i] == '(') cnt++;
            else cnt--;
            if (y[i] == '(') k++;
            else k--;
            if (min(k,cnt) < 0) f = 1;
        }
        cout << ((f) ? "NO" : "YES") << endl;
        if (!f){
            cout << x << endl << y << endl;
        }
    }
    return 0;
}