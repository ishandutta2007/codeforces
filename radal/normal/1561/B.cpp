#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimize ("O2")
#pragma GCC optimize ("unroll-loops")
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
const long long int N=5e5+20,mod = 1e9+7,inf=1e9;
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--){
        int a,b;
        cin >> a >> b;
        if (a > b) swap(a,b);
        vector<int> ve;
        rep(i,0,a+1){
            ve.pb(a-i+(a+b+1)/2-i);
            ve.pb(i+b-((a+b+1)/2-i));
        }
        sort(ve.begin(),ve.end());
        int m = unique(ve.begin(),ve.end())-ve.begin();
        cout << m << endl;
        rep(i,0,m) cout << ve[i] << ' ';
        cout << endl;
    }
}