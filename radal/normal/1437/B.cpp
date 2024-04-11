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
const ll N = 1e5+20,inf = 1e10,mod=1e9+7;
ll dp[N][2];
int main(){
    int T;
    cin >> T;
    while(T--){
        ll n,t0=0,t1=0,cnt0=0,cnt1=0;
        string s;
        cin >> n >> s;
        rep(i,0,n){
            if (s[i] == '0'){
                cnt0++;
                if (cnt1) t1 += cnt1-1;
                cnt1=0;
            }
            else{
                cnt1++;
                if (cnt0) t0 += cnt0-1;
                cnt0 = 0;
            }
        }
        if (cnt0) t0 += cnt0-1;
        if (cnt1) t1 += cnt1-1;
    //    debug(t1);
        cout << max(t0,t1) << endl;
    }
}