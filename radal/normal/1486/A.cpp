#include <iostream>
#include <vector>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O8")
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
const long long int N=1e4+20,mod = 1e9,inf=4e18,maxm = 2e5+20;
const long double eps = 0.0001;
ll pre[N];
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);cout.tie(0);
    int T=1;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        pre[0] = 0;
        bool f = 1;
        rep(i,1,n+1){
            int x;
            cin >> x;
            pre[i] = x+pre[i-1];
            if (pre[i] < i*(i-1)/2) f = 0;
        }
        if (f) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}