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
const long long int N=1e6+30,mod = 1e9+7;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    ll n,sum=0;
    cin >> n;
    vector<ll> a;
    bool e=1;
    rep(i,0,n){
        ll x;
        cin >> x;
        if (x%2) e=0;
        sum+=x;
        a.pb(x);
    }
    rep(i,0,n){
        if (sum-a[i] < a[i]){
            cout << "NO";
            return 0;
        }
    }
    if (!(sum%2)){
        cout << "YES";
        return 0;
    }
    if (sum%2){
        cout << "NO";
        return 0;
    }
 /*   sort(a.begin(),a.end());
    ll p1 = n-1;
    while (p1 > 0){
        ll k = min(a[p1],a[p1-1]);
        a[p1]-=k;
        a[p1-1]-=k;
        if (a[p1]){
            swap(a[p1],a[p1-1]);
            p1--;
            a.pop_back();
        }
        else{
            a.pop_back();
            p1--;
        }
    }
    if (a[0]) cout << "NO";
    else cout << "YES";*/
}