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
const ll N = 2e5+50;
ll a[N];
int main(){
    //think simple!!!
    int n;
    cin >> n;
    rep(i,1,n+1) cin >> a[i];
    int i =1;
    while (i <= n-i+1){
        if (i%2) swap(a[i],a[n-i+1]);
        i++;
    }
    rep(i,1,n+1) cout << a[i] << ' ';

}