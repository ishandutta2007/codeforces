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
ll ans[N];
int main(){
	ios_base::sync_with_stdio(false); cout.tie(0); cin.tie();
    ll k2,k3,k5,k6;
    cin >> k2 >> k3 >> k5 >> k6;
    if (k2 >= min(k5,k6)){
        cout << min(k5,k6) * 256 + min(k2-min(k5,k6),k3)*32;
    }
    else{
        cout << k2 * 256;
    }
    return 0;
}