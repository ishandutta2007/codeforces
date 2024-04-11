#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O2")
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
const long long int N=1e5+10,mod = 1e9+7,inf=1e18,dlt = 12251;
int a[N];
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,k,mx=-1e9;
    cin >> n >> k;
    if (k <= 2) mx *= -1;
    rep(i,0,n){
        cin >> a[i];
        if (k > 2) mx = max(mx,a[i]);
        else mx = min(mx,a[i]);
    }
    if (k != 2) cout << mx;
    if (k==2) cout << max({a[0],a[n-1],mx});
}