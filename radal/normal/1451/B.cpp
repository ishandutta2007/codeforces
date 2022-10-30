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
const long long int N=1e6+30,mod = 1e9+7,inf=1e12;
const long double eps = 0.0001;
bool b[N][2],c[N][2];
int main(){
    int T;
    cin >> T;
    while (T--){
        int n,q;
        string s;
        cin >> n >> q;
        cin >> s;
        b[0][0] = 0;
        b[0][1] = 0;
        c[n-1][0] = 0;
        c[n-1][1] = 0;
        rep(i,1,n){
            b[i][0] = b[i-1][0];
            b[i][1] = b[i-1][1];
            if (s[i-1] == '1') b[i][1] = 1;
            else b[i][0] = 1;
        }
        repr(i,n-2,0){
            c[i][0] = c[i+1][0];
            c[i][1] = c[i+1][1];
            if (s[i+1] == '1') c[i][1] = 1;
            else c[i][0] = 1;
        }
        rep(i,0,q){
            int L,R;
            cin >> L >> R;
            L--;
            R--;
            if (s[L] == '1' && b[L][1]){
                cout << "YES" << endl;
                continue;
            }
            if (s[L] == '0' && b[L][0]){
                cout << "YES" << endl;
                continue;
            }
            if ((s[R] == '1' && c[R][1]) || (s[R] == '0' && c[R][0])){
                cout << "YES"<< endl;
                continue;
            }
            cout << "NO" << endl;
        }
    }
    return 0;
}