#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O8")
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
typedef long long ll;
typedef pair<ll,ll> pll;
const long long int N=2e5+20,mod = 1e9+7,inf=2e18,dlt = 12250,maxm = 131072;
pll h[N];
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        rep(i,1,n+1){
            cin >> h[i].X;
            h[i].Y = i;
        }
        sort(h+1,h+n+1);
        int s = 1;
        ll d = h[2].X-h[1].X;
        rep(i,2,n){
            if (h[i+1].X-h[i].X < d){
                d = h[i+1].X-h[i].X;
                s = i;
            }
        }
        rep(i,s,n+1) if (i != s+1) cout << h[i].X << ' ';
        rep(i,1,s) cout << h[i].X << ' ';
        cout << h[s+1].X;
        cout << endl;
    }
}