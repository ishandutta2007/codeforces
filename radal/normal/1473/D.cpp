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
const long long int N=1e6+20,mod = 1e9+7,inf=3e8;
const long double eps = 0.0001;
int a[N],pre[N],pre2[N];
pair<ll,pll> arr[N],arr2[N];
char c[N];
int MI(int l,int r,int ind){
    if (l == r) return inf;
    if (l == arr[ind].Y.X && r == arr[ind].Y.Y) return arr[ind].X;
    if (l >= arr[ind].Y.X && r <= arr[ind].Y.Y){
        if (arr[2*ind].Y.Y >  l) return MI(l, r, 2*ind);
        return MI(l, r, 2*ind+1);
    }
    if (l < arr[ind].Y.X){
        if (r <= arr[ind*2].Y.Y) return min(MI(arr[ind].Y.X, r,2*ind),MI(l,arr[ind-1].Y.Y,ind-1));
        else return MI(l,r,ind-1);
    }
    if (l > arr[ind].Y.Y-1) return MI(l,r,ind+1);
    return min(MI(l,arr[ind].Y.Y,ind),MI(arr[ind].Y.Y,r,ind+1));
}
int MX(int l,int r,int ind){
    if (l == r) return -inf;
    if (l == arr2[ind].Y.X && r == arr2[ind].Y.Y) return arr2[ind].X;
    if (l >= arr2[ind].Y.X && r <= arr2[ind].Y.Y){
        if (arr2[2*ind].Y.Y >  l) return MX(l, r, 2*ind);
        return MX(l, r, 2*ind+1);
    }
    if (l < arr2[ind].Y.X){
        if (r <= arr2[ind*2].Y.Y) return max(MX(arr2[ind].Y.X, r,2*ind),MX(l,arr2[ind-1].Y.Y,ind-1));
        else return MX(l,r,ind-1);
    }
    if (l > arr2[ind].Y.Y-1) return MX(l,r,ind+1);
    return max(MX(l,arr2[ind].Y.Y,ind),MX(arr2[ind].Y.Y,r,ind+1));
}
int main(){
    int T;
    cin >> T;
    while (T--){
        int n,m; 
        cin >> n >>m;
        rep(i,0,n) cin >> c[i];
        if (c[0] == '+') pre[0] = 1;
        else pre[0] = -1;
        a[0] = pre[0];
        pre2[0] = a[0];
        rep(i,1,n){
            if (c[i] == '+') a[i] = a[i-1]+1;
            else a[i] = a[i-1]-1;
            pre[i] = max(a[i],pre[i-1]);
            pre2[i] = min(pre2[i-1],a[i]);
        }
        //a[n] = 0;
        //n++;
        ll z = 1;
        while (z < n) z*=2;
        while (n < z){
            pre[n] = pre[n-1];
            a[n] = a[n-1];
            pre2[n] = pre2[n-1];
            n++;
        }
        repr(i,2*n-1,n){
            arr[i].X = a[i-n];
            arr[i].Y = {i-n,i-n+1};
            arr2[i] = arr[i];
        }
        repr(i,n-1,0){
            arr[i].X = min(arr[2*i].X,arr[2*i+1].X);
            arr[i].Y = {arr[2*i].Y.X,arr[2*i+1].Y.Y};
            arr2[i].Y = arr[i].Y;
            arr2[i].X = max(arr2[2*i].X,arr2[2*i+1].X);
        }
        rep(i,0,m){
            int l,r;
            cin >> l >> r;
            int mx,mi; 
            l--;
            r--;
            if (l){
                mx = max(pre[l-1],MX(r+1,n,1)-a[r]+a[l-1]);
                mi = min(pre2[l-1],MI(r+1,n,1)-a[r]+a[l-1]);
                if (mi > 0 || mx < 0) mx++;
            }
            else{
                if (r+1 == n) mx = 0;
                else mx = MX(r+1,n,1)-a[r];
                if (r+1 == n) mi = 0;
                else mi = MI(r+1,n,1)-a[r];
                if (mi > 0 || mx < 0) mx++;
            }
            //debug(MI(r+1,n,1));
            if (r+1 == n && !l) cout << 1 << endl;
            else cout << mx-mi+1 << endl;
        }
    }
    return 0;
}