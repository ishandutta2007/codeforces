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
typedef pair<ll,ll> pll;
const long long int N=2e5+30,mod = 1e9+7,inf=1e12;
int main(){
    int T;
    cin >> T;
    while(T--){
        ll n,c0,c1,h,t0=0,t1=0;
        cin >> n >> c0 >> c1 >> h;
        string s;
        cin >> s;
        rep(i,0,n){
            if (s[i] == '0') t0++;
            else t1++;
        }
        if (c0 > c1){
            swap(c0,c1);
            swap(t0,t1);
        }
        cout << min(t1*h+n*c0,c0*t0+c1*t1) << endl;

    }
}