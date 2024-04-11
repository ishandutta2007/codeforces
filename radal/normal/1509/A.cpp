#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O2")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define endl '\n'
#define pb push_back
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
typedef long long ll;
typedef pair<int,int> pll;
const long long int N=1e5+10,mod = 1e9+7,inf=1e18,dlt = 12251;
int a[N];
int main(){
    int T;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        vector<int> a,b;
        rep(i,0,n){
            int x;
            cin >> x;
            if (x%2) a.pb(x);
            else b.pb(x);
        }
        for (int u : a) cout << u << ' ';
        for (int u : b) cout << u << ' ';
        cout << endl;
    }
    return 0;
}