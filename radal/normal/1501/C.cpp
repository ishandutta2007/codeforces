#include <bits/stdc++.h>
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
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pll;
const long long int N=3e6+10,mod = 2e18,inf=1e18;
const long double eps = 0.0001;
int a[N];
int cnt[N];
pll mp[2*N];
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,j=-1;
    cin >> n;
    rep(i,0,n){
        cin >> a[i];
        cnt[a[i]]++;
        if (cnt[a[i]] >= 4) j = a[i];
    }
    if (j != -1){
        int k = 0;
        cout << "YES" << endl;
        rep(i,0,n){
            if (a[i] == j){
                cout << i+1 << ' ';
                k++;
                if (k == 4) return 0;
            }
        }
    }
    ll e = 1e7;
    rep(i,0,e){
        int j = i/n;
        int k =i %n;
        if (j == k || max(j,k) >= n) continue;
        if (mp[a[j]+a[k]] == make_pair(0,0)){
            mp[a[j]+a[k]] = {j+1,k+1};
            continue;
        }
        pll p = mp[a[j]+a[k]];
        if (p.X != j+1 && p.Y != j+1 && p.X != k+1 && p.Y != k+1){
            cout << "YES" << endl;
            cout << j+1 << ' ' << k+1 << ' ' << p.X << ' ' << p.Y;
            return 0;
        }
    }
    cout << "NO";
}