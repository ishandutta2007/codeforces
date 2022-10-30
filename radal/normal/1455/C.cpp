#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
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
const long long int N=1e7+30,mod = 1e9+7,inf=2e5;
const long double eps = 0.0001;
int dp[N];

int main(){
    int T;
    cin >> T;
    while (T--){
        int a,b;
        cin >> a >> b;
        cout << a-1 << ' ' << b << endl;
    }
    return 0;
}