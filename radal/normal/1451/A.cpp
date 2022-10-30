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
ll a[N];
int main(){
    int T;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        if (n == 1){
            cout << 0 << endl;
            continue;
        }
        if (n == 2){
            cout << 1 << endl;
            continue;
        }
        if (n == 3){
            cout << 2 << endl;
            continue;
        }
        if (!(n%2)){
            cout << 2 << endl;
            continue;
        }
        cout << 3 << endl;
    }
    return 0;
}