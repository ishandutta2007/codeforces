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
const long long int N=2e6+20,mod = 1e9+7,inf=4e18,maxm = 2e5+20;
const long double eps = 0.0001;
int p[N];
char c[N];
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);cout.tie(0);
    int n;
    ll ans = 0;
    cin >> n;
    rep(i,0,n) cin >> p[i] >> c[i];
    int r = n-1,nxt1=-1,nxt2=-1;
    while (r > -1 && c[r] != 'G'){
        if (c[r] == 'R'){
            if (nxt1 != -1) ans += p[nxt1]-p[r];
            nxt1 = r;
        }
        else{
            if (nxt2 == -1) nxt2 = r;
            else{
                ans += p[nxt2]-p[r];
                nxt2 = r;
            }
        }
        r--;
    }
    if (r < 0){
        cout << ans;
        return 0;
    }
    if (nxt1 != -1) ans += p[nxt1]-p[r];
    if (nxt2 != -1) ans += p[nxt2]-p[r];
    int l = 0;
    nxt1 = nxt2 = -1;
    while (l <= r && c[l] != 'G'){
        if (c[l] == 'R'){
            if (nxt1 != -1) ans += p[l]-p[nxt1];
            nxt1 = l;
        }
        else{
            if (nxt2 != -1) ans += p[l]-p[nxt2];
            nxt2 = l;
        }
        l++;
    }
    if (nxt1 != -1) ans += p[l]-p[nxt1];
    if (nxt2 != -1) ans += p[l]-p[nxt2];
    if (l == r){
        cout << ans;
        return 0;
    }
    int nxt3 = l,mx1 = 0,mx2 = 0;
    nxt2 = l;
    nxt1 = l;
    l++;
    while(l <= r){
        if (c[l] == 'G'){
            if (nxt1 != -1) mx1 = max(mx1,p[l]-p[nxt1]);
            if (nxt2 != -1) mx2 = max(mx2,p[l]-p[nxt2]);
            ans += min(3*(p[l]-p[nxt3])-mx1-mx2,2*(p[l]-p[nxt3]));
            nxt3 = l;
            mx1 = mx2 = 0;
            nxt1 = l;
            nxt2 = l;
        }
        if(c[l] == 'R'){
            if (nxt1 != -1) mx1 = max(mx1,p[l]-p[nxt1]);
            nxt1 = l;
        }
        if (c[l] == 'B'){
            if (nxt2 != -1) mx2 = max(mx2,p[l]-p[nxt2]);
            nxt2 = l;
        }
        l++;
    }
    cout << ans;
    return 0;
}