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
const long long int N=2e5+30,mod = 1e9+7,inf=1e9;
int main(){
    ll x,y,z;
    cin >> x >> y >> z;
    x -= y;
    if ((x < 0 && x+z >= 0) || (x > 0 && x-z <= 0) || (!x && z)){
        cout << '?';
        return 0;
    }
    if (x < 0){
        cout << '-';
    }
    if (!x){
        cout << 0;
    }
    if (x > 0){
        cout << '+';
    }
    return 0;
}