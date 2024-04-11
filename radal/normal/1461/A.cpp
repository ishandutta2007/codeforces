#include <bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define ll long long int
#define endl '\n'
//#define mp make_pair
#define pb push_back
#define rep(i,l,r) for (ll i=l; i<r; i++)
#define repr(i,r,l) for (ll i=r; i>=l; i--)
using namespace std;
typedef pair<int,int> pll;
const long long int N=1e5+30,inf = 1e9;
int main(){
    int T;
    cin >> T;
    while (T--){
        int n,k;
        cin >> n >> k;
        rep(i,0,n){
            if (i%3 == 0) cout << 'a';
            if (i%3 == 1) cout << 'b';
            if (i%3 == 2) cout << 'c';
        }
        cout << endl;
    }
    return 0;
}