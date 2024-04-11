#include <bits/stdc++.h>
#pragma GCC optimize("O3,no-stack-protector,unroll-loops")
#pragma GCC target("avx2,fma")
#define rep(i,l,r) for (int i = l; i < r; i++)
#define repr(i,r,l) for (int i = r; i >= l; i--)
#define X first
#define Y second
#define pb push_back
#define endl '\n'
#define debug(x) cerr << #x << " : " << x << endl;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pll;
typedef pair<long double,long double> pld;
const long long int N = 1e5+10,mod = 1e9+7,inf = 1e9,sq = 600,maxm = 2e5+10;
inline int mkay(int a,int b){
    if (a+b >= mod) return a+b-mod;
    if (a+b < 0) return a+b+mod;
    return a+b;
}
inline int poww(int n,int k){
    int c = 1;
    while (k){
        if (k&1) c = (1ll*c*n)%mod;
        n = (1ll*n*n)%mod;
        k >>= 1;
    }
    return c;
}
int z[N],cnt[N],mark[N];
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);cout.tie(0);
    string s;
    cin >> s;
    int n = s.size();
    int l = 0,r = 0;
    rep(i,1,n){
        if (i < r)
            z[i] = min(z[i-l],r-i);
        while (i+z[i] < n && s[i+z[i]] == s[z[i]]) z[i]++;
        if (i+z[i] > r){
            l = i;
            r = z[i]+i;
        }
        if (i+z[i] == n)
            mark[z[i]] = 1;
    }
    mark[n] = 1;
    cnt[n] = 1;
    memset(z,0,sizeof z);
    l = 0;
    r = 0;
    rep(i,1,n){
        if (i < r)
            z[i] = min(z[i-l],r-i);
        while (i+z[i] < n && s[i+z[i]] == s[z[i]]) z[i]++;
        if (i+z[i] > r){
            l = i;
            r = z[i]+i;
        }
            cnt[z[i]]++;
        
    }
    int k = 0;
    repr(i,n-1,0){
        cnt[i] += cnt[i+1];
        if (mark[i+1]) k++;
    }
    cout << k << endl;
    rep(i,1,n+1){
        if (mark[i]){
            cout << i << ' ' << cnt[i] << endl;
        }
    }
    return 0;
}