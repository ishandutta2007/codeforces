#include <bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("Ofast")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define ll long long int
#define endl '\n'
#define mp make_pair
#define pb push_back
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
const long long int N=1e6+30,mod = 1e9+7,inf=1e18;
ll a[N],dp[N],one[N],two[N],three[N];
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    ll T;
    cin >> T;
    while (T--){
        string s;
        cin >> s;
        ll n = s.size();
        one[0] = -1;
        two[0] = -1;
        three[0] = -1;
        rep (i,1,n){
            if (s[i-1] == '1'){
                one[i] = i-1;
                two[i] = two[i-1];
                three[i] = three[i-1];
            }
            if (s[i-1] == '2'){
                one[i] = one[i-1];
                two[i] = i-1;
                three[i] = three[i-1];
            }
            if (s[i-1] == '3'){
                one[i] = one[i-1];
                two[i] = two[i-1];
                three[i] = i-1;
            }
        }
        ll ans=inf;
        rep(i,2,n){
            if (s[i] == '1'){
                if (two[i] == -1 || three[i] == -1) continue;
                ans  = min(ans,i-min(two[i],three[i])+1);
            }
            if (s[i] == '2'){
                if (one[i] == -1 || three[i] == -1) continue;
                ans  = min(ans,i-min(one[i],three[i])+1);
            }
            if (s[i] == '3'){
                if (two[i] == -1 || one[i] == -1) continue;
                ans  = min(ans,i-min(two[i],one[i])+1);
            }
        }
        if (ans == inf){
            cout << 0 << endl;
            continue;
        }
        cout  << ans << endl;
    }
    return 0;

}