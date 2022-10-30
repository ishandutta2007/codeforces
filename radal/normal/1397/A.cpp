#include <bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define ll long long int
#define endl '\n'
#define mp make_pair
#define pb push_back
#define rep(i,l,r) for (ll i=l; i<r; i++)
#define repr(i,r,l) for (ll i=r; i>=l; i--)
using namespace std;
const int N=1e3+10;
int main(){ 
    ios:: sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll T;
    cin >> T;
    while(T--){
        ll n;
        cin >> n;
        string s[n];
        ll t[28];
        rep(i,0,28) t[i] = 0;
        rep (i,0,n){
            cin >> s[i];
            rep(j,0,s[i].size()){
                t[int(s[i][j])-int('a')]++;
            }
        }
        bool f=0;
        rep(j,0,28){
            if (t[j]%n){
                cout << "NO" << endl;
               // cout << char(int('a')+j);
                f=1;
                break;
            }
        }
        if (!f) cout << "YES" << endl;
    }
        
    return 0;
}