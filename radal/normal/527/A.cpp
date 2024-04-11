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
const long long int N=5e2+20,mod = 1e9+7,inf=3e16,maxk = 1e5+20;
const long double eps = 0.0001;
int main(){
    ll a,b,cnt=0;
    cin >> a >> b;
    while (b){
        cnt += a/b;
        a%=b;
        swap(a,b);
    }
    cout << cnt;
    return 0;
}