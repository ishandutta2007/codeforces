#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O8")
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
const long long int N=2e5+20,mod = 1e9+7,inf=2e18,dlt = 12250,maxm = 131072;
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--){
        int n;
        ll s=0;
        cin >> n;
        rep(i,0,n){
            int x;
            cin >> x;
            s += x;
        }
        if (s == n){
            cout << 0 << endl;
            continue;
        }
        if (s < n) cout << 1 << endl;
        else cout << s-n << endl;
    }
}