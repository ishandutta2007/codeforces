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
typedef pair <ll,ll>  pll;
const ll N = 1e5+30,inf = 1e10,mod=1e9+7;
bool a[N];
vector <int> r;
void tajz(int n){
    int s=sqrt(n);
    rep(i,1,s+1){
        if (n%i == 0) r.pb(i);
        if ((i != s || s*s != n) && n%i == 0){
      //      debug(n/i);
            r.pb(n/i);
        }
    }
}
int main(){
    int n;
    cin >> n;
    rep(i,0,n) cin >> a[i];
    if (n == 3){
        rep (i,0,3) if (a[i] == 0) { cout << "NO"; return 0;}
        cout << "YES";
        return 0;
    }
    if (n == 4){
        rep(i,0,4) if (a[i] == 0) {cout << "NO"; return 0;}
        cout << "YES";
        return 0;
    }
    tajz(n);
    //int si = r.size();
    //cout << r[3];
    for (int p : r){
     //   debug(k);
        if (p >= n/2+n%2) continue;
        //debug(p);
        rep(i,0,p){
            bool f=1;
            int m = n/p;
            int p1=i;
            while (p1 < n){
 //               debug(p);
                if (a[p1] == 0){
                    f=0;
                    break;
                }
                p1+=p;            
            }
            if (f == 1){
                cout << "YES" << endl;
                return 0;
            }
        }
   }
    cout << "NO";
}