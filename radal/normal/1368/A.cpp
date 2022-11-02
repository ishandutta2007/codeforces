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
typedef pair<ll,ll> pll;
const long long int N=1e3+20,mod = 1e9,inf=4e18,maxm = 2e5+20;
const long double eps = 0.0001;
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);cout.tie(0);
    int T;
    cin >> T;
    while (T--){
        int n,a,b,cnt = 0;
        cin >> a >> b >> n;
        while (a <= n && b <= n){
            if (a > b) swap(a,b);
            a += b;
            cnt++;
        }
        cout << cnt << endl;
    }
    return 0;
}