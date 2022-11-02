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
int main(){
    ll n,a,b;
    cin >> a  >> b >> n;
    if (a == b){
        cout << 1;
        return 0;
    }
    if (a == -b && n%2){
        cout << -1;
        return 0;
    }
    if (b == 0){
        cout << 0;
        return 0;
    }
    if (a == 0 || abs(b)%abs(a)){
        cout << "No solution";
        return 0;
    }
    if ((a < 0 && b > 0 && !n%2) || (a > 0 && b < 0 && !n%2)){
        cout << "No solution";
        return 0;
    }
    if (n%2){
        if (a > 0 && b > 0){
            b/=a;
            ll t=2;
            while (pow(t,n) < b) t++;
            if (pow(t,n) > b) cout << "No solution";
            else cout << t;
            return 0;
        }
        if (a > 0 && b < 0){
            b*=-1;
            b/=a;
            ll t=1;
            while (pow(t,n) < b) t++;
            if (pow(t,n) > b) cout << "No solution";
            else cout << -t;
            return 0;
        }
        if (a < 0 && b < 0){
            b*=-1;
            a*=-1;
            b/=a;
            ll t=1;
            while (pow(t,n) < b) t++;
            if (pow(t,n) > b) cout << "No solution";
            else cout << t;
            return 0;
        }
        if (a < 0 && b > 0){
            a*=-1;
            b/=a;
            ll t=1;
            while (pow(t,n) < b) t++;
            if (pow(t,n) > b) cout << "No solution";
            else cout << -t;
            return 0;
        }
    }
    if (a > 0 && b > 0){
        b/=a;
        ll t=1;
        while (pow(t,n) < b) t++;
        if (pow(t,n) > b) cout << "No solution";
        else cout << t;
        return 0;
    }
    if (a < 0 && b < 0){
        b*=-1;
        a*=-1;
        b/=a;
        ll t=1;
        while (pow(t,n) < b) t++;
        if (pow(t,n) > b) cout << "No solution";
        else cout << t;
        return 0;
    }



}