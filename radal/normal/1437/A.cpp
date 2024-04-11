#include <bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define ll long long int
#define mp make_pair
#define pb push_back
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
typedef pair <ll,ll>  pll;
const ll N = 1e3+20,inf = 1e10,mod=1e9+7;
int main(){
    int T;
    cin >> T;
    while(T--){
        ll l,r;
        cin >> l >> r;
        if (l >= (r+1)/2+(r+1)%2){
            cout<<"YES" << endl;
            continue;
        }
        cout << "NO" << endl;
    }
}