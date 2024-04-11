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
    bool f = 1;
    int cnt1 = 0,cnt2 = 0;
    int n;
    cin >> n;
    rep(i,0,n){
        int x;
        cin >> x;
        if (x == 25){
            cnt1++;
            continue;
        }
        if (x == 50){
            if (cnt1 == 0) f = 0;
            else{
                cnt2++;
                cnt1--;
            }

        }
        if (x == 100){
            if (cnt2 && cnt1){
                cnt2--;
                cnt1--;
                continue;
            }
            if (cnt1 >= 3){
                cnt1 -= 3;
                continue;
            }
            f = 0;
        }
    }
    (!f) ? cout << "NO" : cout << "YES" << endl;
    return 0;
}