#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O2")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define endl '\n'
#define pb push_back
#define mp make_pair
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
typedef long long ll;
typedef pair<int,int> pll;
const long long int N=1e5+10,mod = 1e9+7,inf=1e18,dlt = 12251;
int main(){
    ll l,r;
    cin >> l >> r;
    if (l == r){
        cout<<0;
        return 0;
    }
    int ans = 64;
    int cnt;
    l ^= r;
    cnt = __builtin_clzll(l);

    cout << (1ll << (64-cnt))-1;
}