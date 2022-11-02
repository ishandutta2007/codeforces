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
const long long int N=1e2+20,mod = 1e9+7,inf=2e18,maxk = 1e5+20;
const long double eps = 0.0001;
int main(){
    ios :: sync_with_stdio(0);
    string s;
    cin >> s;
    int n = s.size(),ans = 0;
    rep(i,0,n){
        int cnt = 1,ind = i;
        rep(j,i+1,n){
            if (s[j] == s[i] && (j-ind)%2){
                cnt++;
                ind = j;
            }
        }
        ans = max(ans,cnt);
    }
    cout << ans;
    return 0;
}