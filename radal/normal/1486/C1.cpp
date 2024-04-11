#include <iostream>
#include <vector>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O8")
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
typedef pair<ll,ll> pll;
const long long int N=1e3+20,mod = 1e9,inf=4e18,maxm = 2e5+20;
const long double eps = 0.0001;
void f(int l,int r){
    int m,x,y;
    while (r-l > 1){
        cout << "? " << l << ' ' << r << endl;
        cin >> x;
        m = (r+l)/2;
        if (x <= m){
            cout << "? " << l << ' ' << m << endl;
            cin >> y;
            if (x == y) r = m;
            else l = m;
        }
        else{
            cout << "? " << m << ' ' << r << endl;
            cin >> y;
            if (x == y) l = m;
            else r = m;
        }
    }
    if (l == r) cout << "! " <<  l << endl;
    else{
        cout << "? " << l << ' ' << r << endl;
        int x;
        cin >> x;
        if (x == l){
            cout << "! " << r << endl;
            return;
        }
        cout << "! " << l << endl;
    }
}
int main(){
    //ios :: sync_with_stdio(0); cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    f(1,n);
    return 0;
}