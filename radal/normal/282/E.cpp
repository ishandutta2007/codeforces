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
typedef long long ll;
typedef pair<int,int> pll;
const long long int N=4e6+20,mod = 1e9+7,inf=1e9,dlt = 12250,maxm = 2e6;
int poww(ll a,int k){
    if (!k) return 1;
    if (k == 1) return a;
    ll r = poww(a,k/2);
    return (((r*r)%mod)*poww(a,k&1))%mod;
}
int trie[N][3],cnt;
ll a[N/10];
void build(string s){
    int p = 0;
    string t="";
    for(char ch : s){
        int u = ch-'0';
        t+=ch;
        if (!trie[p][u]){
            cnt++;
            trie[p][u]=cnt;
        }
        p = trie[p][u];
    }
}
ll que(ll x){
    int p = 0,h = 0;
    ll y=0;
    rep(i,0,40){
        if(!trie[p][0] && !trie[p][1]) return y;
        bool f  = (!(x&(1ll << (39-i))));
        if (!trie[p][0] || (trie[p][1] && f)){
            if (f)
                y += (1ll << (39-i));
            p = trie[p][1];
            continue;
        }
        if (!f)
            y += (1ll << (39-i));
        p = trie[p][0];
    }
    return y;
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    ll x=0;
    cin >> n;
    rep(i,0,n){
        cin >> a[i];
        x ^= a[i];
    }
    ll ans = x;
    string st="";
    rep(i,0,40) st+='0';
    build(st);
    ll y = 0;
    rep(i,0,n){
        x ^= a[i];
        y ^= a[i];
        string s="";
        rep(j,0,40){
            if (y&(1ll << j)) s='1'+s;
            else s = '0'+s;
        }
        build(s);
        ans = max(que(x),ans);
    }
    cout << ans;
    return 0;
}