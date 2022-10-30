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
const long long int N=2e5+30,mod = 1e9+7,inf=1e12;
ll a[N];
int main(){
    int T;
    cin >> T;
    vector<ll> ve;
    while (T--){
        ll n,w,sum=0;
        ve.clear();
        cin >> n >> w;
        rep(i,0,n){
            cin >> a[i];
        }
        rep (i,0,n){
            if (a[i] <= w){
                if (a[i] >= w/2+w%2){
                    ve.clear();
                    sum = a[i];
                    ve.pb(i+1);
                    break;
                }
                ve.pb(i+1);
                sum += a[i];
                if (sum >= w/2+w%2){
                    break;
                }
            }
        }
        if (!ve.size() || sum < w/2+w%2) cout << -1 << endl;
        else{
            cout << ve.size() << endl;
            for (int u : ve){
                cout << u << ' ';
            }
            cout << endl;
        }
    }
    return 0;
}