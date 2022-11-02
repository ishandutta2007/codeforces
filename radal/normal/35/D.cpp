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
#define rep(i,l,r) for (ll i=l; i<r; i++)
#define repr(i,r,l) for (ll i=r; i>=l; i--)
using namespace std;
const long long int N=2e5+30,mod = 998244353;
ll c[N];
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
    ll n,x;
    cin >> n >> x;
    rep (i,0,n){
        ll y;
        cin >> y;
        c[i] = y*(n-i);
    }
    sort(c,c+n);
    ll sum=0, i = 0;
    while (i < n && sum+c[i] <= x){
        sum+=c[i];
        i++;
    }
    cout << i;
}