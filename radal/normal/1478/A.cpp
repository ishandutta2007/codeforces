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
const long long int N=5e2+20,mod = 1e9+7,inf=8e18,maxk = 1e5+20;
const long double eps = 0.0001;
int a[N],mark[N];
int main(){
    int T;
    cin >> T;
    while (T--){
        memset(mark,0,sizeof mark);
        int n;
        cin >> n;
        rep(i,0,n){
            cin >> a[i];
        }
        int t = 1;
        rep(i,0,n){
            if (!mark[i]){
                mark[i] = t;
                int p = a[i];
                int ind = i+1;
                while (ind < n){
                    if (!mark[ind] && a[ind] > p){
                        mark[ind] = t;
                        p = a[ind];
                    }
                    ind++;
                }
                t++;
            }
        }
        cout << t-1 << endl;

    }
    return 0;

}