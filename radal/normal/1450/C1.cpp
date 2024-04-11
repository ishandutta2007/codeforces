#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O8")
#pragma GCC optimization ("unroll-loops")
//#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define endl '\n'
#define pb push_back
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
typedef long long  int ll;
typedef pair<int,int> pll;
const long long int N=3e2+20,mod = 1e9+7,inf=2e8;
const long double eps = 0.0001;
string a[N],b[N],c[N],d[N];
int n;
inline bool bad(int i,int j){
    char X = a[i][j];
    return ((i > 1 && a[i-1][j] == X && a[i-2][j] == X) || (j > 1 && a[i][j-1] == X || a[i][j-2] == X) || (i < n-2 && a[i+1][j] == X && a[i+2][j] == X) || (j < n-2 && a[i][j+1] == X && a[i][j+2] == X) || (i && i < n-1 && a[i-1][j] == X && a[i+1][j] == X) || (j && j < n-1 && a[i][j-1] == X && a[i][j+1] == X));
}
int main(){
    int T;
    cin >> T;
    while (T--){
        cin >> n;
        rep(i,0,n){
            cin >> a[i];
            b[i] = a[i];
        }
        int t1=0,t2=0,t3=0,k=0;
        rep(i,0,n){
            rep(j,0,n){
                if ((i+j) % 3 == 0 && a[i][j] != '.' && bad(i,j)){
                    if (a[i][j] == 'X') a[i][j] = 'O';
                    else a[i][j] = 'X';
                    t1++;
                }
                if (a[i][j] != '.') k++;
            }
        }
        if (t1 <= k/3){
            rep(i,0,n) cout << a[i] << endl;
            continue;
        }
        rep(i,0,n) rep(j,0,n) a[i] = b[i];
        rep(i,0,n){
            rep(j,0,n){
                if ((i+j) % 3 == 1 && a[i][j] != '.' && bad(i,j)){
                    if (a[i][j] == 'X') a[i][j] = 'O';
                    else a[i][j] = 'X';
                    t2++;
                }
            }
        }
        if (t2 <= k/3){
            rep(i,0,n) cout << a[i] << endl;
            continue;
        }
        rep(i,0,n) rep(j,0,n) a[i] = b[i];
        rep(i,0,n){
            rep(j,0,n){
                if ((i+j) % 3 == 2 && a[i][j] != '.' && bad(i,j)){
                    if (a[i][j] == 'X') a[i][j] = 'O';
                    else a[i][j] = 'X';
                    t3++;
                }
            }
        }
        rep(i,0,n) cout << a[i] << endl;
        continue;
    }
}