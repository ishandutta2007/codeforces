#include <bits/stdc++.h>
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
const long long int N=5e5+20,mod = 1e9+7,inf=4e18,maxm = 2e5+20;
const long double eps = 0.0001;
int main(){
    int c,r;
    cin >> c >> r;
    string s;
    rep(i,0,c) cin >> s;
    int l = 0;
    while (l < r && s[l] == '.') l++;
    if (l == r){
        cout << 0;
        return 0;
    }
    int cnt = 0;
    while (l < r){
        while (l < r && s[l] == 'B') l++;
        cnt++;
        while (l < r && s[l] == '.') l++;
    }
    cout << cnt;
    return 0;
}