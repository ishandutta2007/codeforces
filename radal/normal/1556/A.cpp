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
typedef long long ll;
typedef pair<int,int> pll;
const long long int N=1e3+20,mod = 1e9+7,inf=1e9,maxm = 1e6+1;
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--){
        int c,d;
        cin >> c >> d;
        if ((abs(c-d))&1){
            cout << -1 << endl;
            continue;
        }
        if (!c && !d){
            cout << 0 << endl;
            continue;
        }
        if (abs(c) == abs(d)){
            cout << 1 << endl;
            continue;
        }
        cout << 2 << endl;
        continue;
    }
    return 0;
}