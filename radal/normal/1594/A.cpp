#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#pragma GCC target("avx2,fma")
#define rep(i,l,r) for (int i = l; i < r; i++)
#define repr(i,r,l) for (int i = r; i >= l; i--)
#define X first
#define Y second
#define pb push_back
#define endl '\n'
#define debug(x) cerr << #x << " : " << x << endl;
using namespace std;
typedef long long ll;
typedef pair<int,int> pll;
const int N = 1e5+20,mod = 1e9+7,inf = 2e9,sq = 400;
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--){
        ll n;
        cin >> n;
        if (n&1){
            cout << n/2 << ' ' << n/2+1 << endl;
            continue;
        }
        cout << -(n-1) << ' ' << n << endl;
    }
}