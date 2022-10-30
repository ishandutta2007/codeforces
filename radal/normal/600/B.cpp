#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O3")
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
typedef long long  int ll;
typedef pair<int,int> pll;
const long long int N=2e5+30,mod = 1e9+7,inf=1e12;
ll a[N],b[N];
int n,m;
int main(){
    cin >> n >> m;
    rep(i,0,n)
        cin >> a[i];
    rep (i,0,m)
        cin >> b[i];
    sort(a,a+n);
    rep(i,0,m){
        cout << upper_bound(a,a+n,b[i])-a << ' ';
    }
    return 0;
}