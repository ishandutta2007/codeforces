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
const long long int N=5e2+30,mod = 1e9+7,inf=2e5;
const long double eps = 0.0001;
int a[N];

int main(){
    int T;
    cin >> T;
    while (T--){
        int n,x,j=-1;
        bool f = 0;
        cin >> n >> x;
        rep(i,0,n){
            cin >> a[i];
            if (i && a[i] < a[i-1]) j = i-1;
        }
        int ans = 0;
        rep(i,0,n){
            if (!i){
                if (j > 0 && a[i] > x){
                    swap(a[i],x);
                    ans++;
                }
                continue;
            }
            if ((a[i] < a[i-1] || i <= j) && a[i-1] > x){
                swap(a[i-1],x);
                ans++;
            }
            if (a[i] < a[i-1]){
                f = 1;
                break;
            }
        }
        if (f){
            cout << -1 << endl;
            continue;
        }
        //if (n >= 2 && a[0] > a[1]) ans++;
        cout << ans << endl;
    }
    return 0;
}