#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O3")
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
const long long int N=2e5+20,mod = 1e9+7,inf=8e18,maxk = 1e5+20;
const long double eps = 0.0001;
ll cnt[N],cnt2[N];
int main(){
    int T;
    cin >> T;
    while (T--){
        ll n,x,y;
        cin >> n;
        y = n%2020;
        if (2021*y > n){
            cout << "NO" <<endl;
            continue;
        }
        cout << "YES" << endl;
    }
    return 0;
}