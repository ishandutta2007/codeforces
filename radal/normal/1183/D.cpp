#include <bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("Os")
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
const int N=1e2+30;
int main(){
    ll T;
    cin >> T;
    while (T--){
        ll n;
        cin >> n;
        vector <ll> cnt(n,0);
        rep(i,0,n){
            ll x;
            cin >> x;
            cnt[x-1]++;
        }
        sort(cnt.begin(),cnt.end());
        ll ans=cnt[n-1],p=cnt[n-1];
        repr(i,n-2,0){
         //   debug(i);debug(cnt[i]);debug(ans);
            if (cnt[i] == 0 || p == 1) break;
            if (cnt[i] >= p){
                ans+=p-1;
                p--;
            }
            else{
                ans += cnt[i];
                p = cnt[i];
            }
        }
        cout << ans << endl;
    }
}