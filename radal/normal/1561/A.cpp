#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimize ("O2")
#pragma GCC optimize ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define endl '\n'
#define pb push_back
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
typedef long long ll;
typedef pair<int,int> pll;
const long long int N=5e5+20,mod = 1e9+7,inf=1e9;
int a[N];
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        rep(i,0,n) cin >> a[i];
        int i = 1;
        while (true){
            bool f = 1;
            rep(i,0,n) if (a[i] != i+1) f = 0;
            if (f) break;
            if (i&1){
                for (int i = 0; i < n-1; i+=2)
                    if (a[i] > a[i+1]) swap(a[i],a[i+1]);
            }
            else{
                for (int i = 1; i < n; i +=2)
                    if (a[i] > a[i+1]) swap(a[i],a[i+1]);
            }
            i++;
        }
        cout << i-1 << endl;
    }
}