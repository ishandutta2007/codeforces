#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define endl '\n'
#define pb push_back
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
typedef long long  int ll;
typedef pair<int,int> pll;
const long long int N=2e5+20,mod = 1e9+7,inf=2e9;
const long double eps = 0.0000001;
long double n,l,v1,v2,k;
bool check(long double x){
    long double t = (l - v1*x)/(v2-v1);
    long double c = l/v1;
    if (c <= x) return 1;
    int n1 = n;
    long double time = 0;
    while (n1 > 0){
        time += t;
        if (time > x) return 0;
        n1 -= k;
        if (n1 <= 0) break;
        time += t*(v2-v1)/(v2+v1);
    }
    return (time <= x);
}
long double binary(long double l,long double r){
    if (check(l)) return l;
    long double m;
    rep(i,0,10000){
        m = (l+r)/2;
        if (check(m)) r = m;
        else l = m;
    }
    return r;
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> l >> v1 >> v2 >> k;
    cout << fixed << setprecision(7) << binary(0,inf);
    return 0;
}