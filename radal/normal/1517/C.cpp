#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O2")
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
const long long int N=5e2+10,mod = 1e9+7,inf=1e18,dlt = 12251;
int poww(int n,int k){
    if (!k) return 1;
    if (k == 1) return n;
    ll r = poww(n,k/2);
    return (((r*r)%mod)*poww(n,k&1))%mod;
}
int reg[N][N];
int p[N];
int main(){
    int n;
    cin >> n;
    rep(i,0,n){
        cin >> p[i];
        reg[i][i] = p[i];
    }
    rep(i,0,n){
        int x = i,y = i,sz = p[i]-1;
        while (sz){
            while (sz && y-1 >= 0 && !reg[x][y-1]){
                y--;
                reg[x][y] = p[i];
                sz--;
            }
            while (sz && x+1 < n && !reg[x+1][y]){
                x++;
                reg[x][y] = p[i];
                sz--;
                if (y && !reg[x][y-1]) break;
            }
            if (sz && (!y || reg[x][y-1]) && (x+1 >= n || reg[x+1][y])){
                cout<< -1;
                return 0;
            }
        }
    }
    rep(i,0,n){
        rep(j,0,i+1){
            cout << reg[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}