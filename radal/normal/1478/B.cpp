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
typedef pair<ll,ll> pll;
const long long int N=1e4+20,mod = 1e9+7,inf=8e18,maxk = 1e5+20;
const long double eps = 0.0001;
int a[N];
int main(){
    int T;
    cin >> T;
    while (T--){
        int q,d;
        cin >> q >> d;
        rep(i,0,q){
            cin >> a[i];
            int x = a[i];
            if (x > 99){
                cout << "YES" << endl;
                continue;
            }
            if (x < 10){
                if (x%d == 0) cout << "YES" << endl;
                else cout << "NO" << endl;
                continue;
            }
            if (x%d == 0){
                cout << "YES" << endl;
                continue;
            }
            if (x/10 >= d){
                cout << "YES" << endl;
                continue;
            }
            while (x > d){
                if (x%10 == d){
                    x = 0;
                    break;
                }
                x-=d;
            }
            (!x) ? cout << "YES" << endl : cout << "NO" << endl;
        }

    }
    return 0;

}