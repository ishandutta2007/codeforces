#include <bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("Os")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define ll unsigned long long int
#define endl '\n'
#define mp make_pair
#define pb push_back
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
const int N=2e3+30;
int main(){
    int T;
    cin >> T;
    while (T--){       
        ll n;
        cin >> n;
        ll cnt[N];
        rep(i,0,N){
            cnt[i]=0;
        }
        rep(i,0,n){
            ll x;
            cin >> x;
            cnt[x]++;
        }
        ll p1=0,p2=0;
        while (cnt[p1] >= 2){
            p1++;
            p2++;
        }
        while (cnt[p1] >= 1){
            p1++;
        }
        debug(p1);debug(p2);
        cout << p1+p2 << endl;
    }
    return 0;
}