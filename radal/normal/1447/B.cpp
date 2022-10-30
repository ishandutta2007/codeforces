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
const long long int N=1e2+30,mod = 1e9+7,inf=1e12;
int a[N][N];
int main(){
    int T;
    cin >> T;
    while (T--){
        int n,m,cnt=0,mi=10000,sum=0;
        cin >> n >> m;
        rep(i,0,n){
            rep(j,0,m) {
                cin >> a[i][j];
                mi = min(mi,abs(a[i][j]));
                if (a[i][j] < 0) cnt++;
                sum += abs(a[i][j]);
            }
        }
        if (cnt%2) cout << sum-2*mi;
        else cout << sum;
        cout << endl;
    }
    return 0;
}