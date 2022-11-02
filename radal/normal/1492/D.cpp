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
const long long int N=2e5+20,mod = 1e9+7,inf=4e18,maxm = 2e5+20;
const long double eps = 0.0001;
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);cout.tie(0);
    int a,b,k,n;
    cin >> a >> b >> k;
    n = a+b;
    if (b == 1){
        if (!k){
            cout << "YES" << endl;
            cout << 1;
            rep(i,0,a) cout << 0;
            cout << endl;
            cout << 1;
            rep(i,0,a) cout << 0;
            cout << endl;
            return 0;
        }
        cout << "NO" << endl;
        return 0;
    }
    if (!k){
        cout << "YES" << endl;
        string s;
        rep(i,0,b) s += '1';
        rep(i,0,a) s += '0';
        cout << s << endl << s;
        return 0;
    }
    if (!a){
        if (k) cout << "NO" << endl;
        else{
            cout << "YES" << endl;
            rep(i,0,b) cout << 1;
            cout << endl;
            rep(i,0,b) cout << 1;
        }
        return 0;
    }
    if (k > a+b-2){
        cout << "NO" << endl;
        return 0;
    }
    string s,t;
    t += '1';
    s += '0';
    a--;
    b--;
    k--;
    while (k && a){
        s = '0'+s;
        t = '0'+t;
        k--;
        a--;
    }
    while (k){
        s = '1' + s;
        t = '1' + t;
        k--;
        b--;
    }
    s = '1'+s;
    t = '0'+t;
    while (a){
        s = '0'+s;
        t = '0'+t;
        a--;
    }
    while (b){
        s = '1'+s;
        t = '1'+t;
        b--;
    }
    cout << "YES" << endl << s << endl << t;
    return 0;
}