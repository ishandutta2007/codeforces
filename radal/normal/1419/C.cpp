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
const long long int N=3e5+30;
ll a[N],b[N];
int main(){
	ios_base::sync_with_stdio(false); cout.tie(0); cin.tie();
    ll T;
    cin >> T;
    while (T--){
        ll n,x,sum=0,t=0;
        cin >> n >> x;
        ll a[n];
        bool f=1;
        rep (i,0,n){
            cin >> a[i];
            if (a[i] != x){
                f = 0;
                t++;
            }
            sum += x-a[i];
        }
        if (f){
            cout << 0 << endl;
            continue;
        }
        if (sum == 0 || t <= n-1){
            cout << 1 << endl; 
            continue;
        }
        cout << 2 << endl;
    }
    return 0;
}