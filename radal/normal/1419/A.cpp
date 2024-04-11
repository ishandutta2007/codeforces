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
        ll n;
        string s;
        cin >> n >> s;
        if (n%2){
            bool f=0;
            for (int i=0; i<n; i+=2){
                ll m = int(s[i])-int('0');
                if (m%2) f = 1;
            }
            if (f) cout << 1 << endl;
            else cout << 2 << endl;
        }
        else{
            bool f=0;            
            for (int i=1; i<n; i+=2){
                ll m = int(s[i])-int('0');
                if (m%2 == 0) f = 1;
            }
            if (f) cout << 2 << endl;
            else cout << 1 << endl;

        }
    }
    return 0;
}