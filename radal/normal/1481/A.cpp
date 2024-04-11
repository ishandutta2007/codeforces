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
const long long int N=5e2+20,mod = 1e9+7,inf=8e18,maxk = 1e5+20;
const long double eps = 0.0001;
int main(){
    int T;
    cin >> T;
    while (T--){
        int x,y,n;
        string s;
        cin >> x >> y >> s;
        n = s.size();
        int u=0,d=0,r=0,l=0;
        rep(i,0,n){
            if (s[i] == 'U') u++;
            if (s[i] == 'D') d++;
            if (s[i] == 'L') l++;
            if (s[i] == 'R') r++;
        }
        if (x < 0){
            x = -x;
            swap(l,r);
        }
        if (y < 0){
            y = -y;
            swap(u,d);
        }
        if (u >= y && r >= x){
            cout << "YES" << endl;
        }
        else cout << "NO" << endl;
    }
    return 0;
}