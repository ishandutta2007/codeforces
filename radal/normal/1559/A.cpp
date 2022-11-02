#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimize ("O2")
#pragma GCC optimize ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define endl '\n'
#define pb push_back
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
typedef long long  int ll;
typedef pair<int,int> pll;
const long long int N=1e5+20,mod = 1e9+7,inf=8e18;
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        int ans,x;
        rep(i,0,n){
            if (!i) cin >> ans;
            else{
                cin >> x;
                ans &= x;
            }
        }
        cout << ans << endl;
    }
    return 0;
}