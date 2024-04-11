#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define endl '\n'
#define pb push_back
#define mp make_pair
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
typedef long long  int ll;
typedef pair<int,int> pll;
const long long int N=1e5+30,mod = 1e9+7,inf=1e12;
vector<int> ve;
int main(){
    int n,d;
    ll ans=0;
    cin >> n >> d;
    rep(i,0,n){
        int x;
        cin >> x;
        ve.pb(x);
    }
    sort(ve.begin(),ve.end());
    rep(i,0,n){
        ll ind = upper_bound(ve.begin(),ve.end(),ve[i]+d)-ve.begin();
        ind -= (i+1);
        ans += ind*(ind-1)/2;
    }
    cout<< ans;
    return 0;
}