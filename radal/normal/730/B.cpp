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
#define pb push_back#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
typedef pair<ll,pair<ll,ll> > pll;
const long long int N=1e5+30,inf = 1e18,mod=1e9+7;
pair<ll,ll> solver(ll n,ll start){
    if (n == 2){
        cout << "? " << start << ' ' << start+1 << endl;
        char c;
        cin >> c;
        if (c == '>') return {start+1,start};
        else return {start,start+1};
    }
    if (n%2){
        pair<ll,ll> p = solver(n-1,start+1);
        cout << "? " << start << ' ' << p.X << endl;
        char c;
        cin >> c;
        if (c == '<') return {start,p.Y};
        cout << "? " << start << ' ' << p.Y << endl;
        cin >> c;
        if (c == '>') return {p.X,start};
        return p;
    }
    else{
        pair<ll,ll> p = solver(n-2,start+2);
        cout << "? " << start << ' ' << start+1 << endl;
        char c;
        cin >> c;
        pair <ll,ll> pe;
        if (c == '<') pe = {start,start+1};
        else pe = {start+1,start};
        cout << "? " << p.X << ' '<<pe.X<<endl;
        cin >> c;
        if (c == '>') p.X = pe.X;
        cout << "? " << p.Y << ' ' << pe.Y<<endl;
        cin >> c;
        if (c == '<') p.Y = pe.Y;
        return p;
    }
}
int main(){
    ios :: sync_with_stdio(0);
    ll T;
    cin >> T;
    while (T--){
        ll n;
        cin >> n;
        if (n == 1){ cout << "! " << 1 << ' ' <<1 << endl; continue;}
        pair<ll,ll> p = solver(n,1);
        cout << "! " << p.X << ' '<<p.Y << endl;
    }
}