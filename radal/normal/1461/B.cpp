#include <bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define ll long long int
#define endl '\n'
//#define mp make_pair
#define pb push_back
#define rep(i,l,r) for (ll i=l; i<r; i++)
#define repr(i,r,l) for (ll i=r; i>=l; i--)
using namespace std;
typedef pair<int,int> pll;
const long long int N=5e2+30,inf = 1e9;
int dpl[N][N],dpr[N][N];
string s[N];
int main(){
    int T;
    cin >> T;
    while (T--){
        int n,m;
        cin >> n >> m;
        rep(i,0,n){
            cin >> s[i];
            dpl[i][0]  = 0;
            dpr[i][m-1] = 0;
            rep(j,1,m){
                if (s[i][j] == '.') continue;
                if (s[i][j-1] == '*') dpl[i][j] = dpl[i][j-1]+1;
                else dpl[i][j] =  0;
            }
            repr(j,m-2,0){
                if (s[i][j] == '.') continue;
                if (s[i][j+1] == '*') dpr[i][j] = dpr[i][j+1]+1;
                else dpr[i][j] =  0;
            }
        }
        ll ans = 0;
        rep(i,0,n){
            rep(j,0,m){
                rep(k,0,n-i){
                    if (s[i+k][j] == '.') break;
                    else if (min(dpl[i+k][j],dpr[i+k][j]) >= k) ans++;
                    else break;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}