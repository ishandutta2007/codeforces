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
        cin >> n;
        ll jump=2,t=1,sum=1,p=1;
        while (sum+(p+jump)*(p+jump+1)/2 <= n){
            sum += (p+jump)*(p+jump+1)/2;
            t++;
            p += jump;
            jump*=2;
        }
        cout << t<<endl;
    }
    return 0;
}