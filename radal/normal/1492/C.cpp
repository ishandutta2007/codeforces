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
int a[N],l[N],r[N];
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);cout.tie(0);
    int m,n;
    string s,t;
    cin >> m >> n;
    cin >> t >> s;
    int p =0;
    rep(i,0,n){
        while (t[p] != s[i]) p++;
        l[i] = p;
        p++;
    }
    p = m-1;
    repr(i,n-1,0){
        while(t[p] != s[i]) p--;
        r[i] = p;
        p--;
    }
    int mx = 0;
    rep(i,0,n){
        if (!i) a[i] = l[i];
        else{
            mx = max(mx,r[i]-a[i-1]);
            a[i] = l[i];
        }
    }
    rep(i,1,n) mx = max(mx,a[i]-a[i-1]);
    cout << mx;
    return 0;
}