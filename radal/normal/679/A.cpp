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
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
typedef pair<ll,pair<ll,ll> > pll;
const long long int N=1e5+30,inf = 1e18,mod=1e9+7;
int main(){
    ios :: sync_with_stdio(0);
    ll a[4] = {2,3,5,7};
    ll t=0,j=-1;
    rep(i,0,4){
        cout << a[i] << endl;
        string s;
        cin >> s;
        if (s == "yes"){
            t++;
            j=i;
        }
    }
    if(t == 0){
        cout << "prime" << endl;
        return 0;
    }
    if (t >= 2){
        cout << "composite" << endl;
        return 0;
    }
    ll b[12] = {a[j]*a[j],11,13,17,19,23,29,31,37,41,43,47};
    rep(i,0,12){
        cout << b[i] << endl;
        string s;
        cin >> s;
        if (s == "yes"){
            cout << "composite" << endl;
            return 0;
        }
    }
    cout << "prime";
}