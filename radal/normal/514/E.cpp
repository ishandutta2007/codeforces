#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#pragma GCC target("avx2,fma")
#define rep(i,l,r) for (int i = l; i < r; i++)
#define repr(i,r,l) for (int i = r; i >= l; i--)
#define X first
#define Y second
#define pb push_back
#define endl '\n'
#define debug(x) cerr << #x << " : " << x << endl;
using namespace std;
typedef long long ll;
typedef pair<int,int> pll;
const long long int N = 3e5+20,mod = 1e9+7,inf = 2e18,sq = 400;
inline int mkay(int a,int b){
    if (a+b >= mod) return a+b-mod;
    return a+b;
}
struct matrix{
    int n,m;
    vector< vector<int> > a;
    matrix (int n,int m,bool f) : n(n),m(m){
        a.resize(n);
        rep(i,0,n){
            a[i].resize(m);
            fill(a[i].begin(),a[i].end(),0);
            if (f) a[i][i] = 1;
        }
        return;
    }
    vector<int>& operator[](int i){
        return a[i];
    }
    matrix operator *(const matrix &b){
        matrix c = matrix (n,b.m,0);
        rep(i,0,n)
            rep(k,0,m)
                rep(j,0,b.m)
                    c[i][j] = mkay(c[i][j],1ll*a[i][k]*b.a[k][j]%mod);
        return c;
    }
    void print(){
        rep(i,0,n){
            rep(j,0,m) cout << a[i][j] << ' ';
            cout << endl;
        }
    }
};
matrix powwmat(matrix a,ll k){
    matrix c = matrix(a.n,a.m,1);
//    rep(i,1,a.n) a[i][i] = 0;
    while(k){
        if (k&1) c = c * a;
        a = a * a;
        k /= 2;
    }
    return c;
}
int cnt[N],d[N];
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    matrix a = matrix(101,101,1);
    int n,x;
    cin >> n >> x;
    rep(i,0,n){
        cin >> d[i];
        cnt[d[i]]++;
    }
    rep(i,0,100)
        a[0][i] = cnt[i+1];
    a[0][100] = 1;
    rep(i,1,100){
        a[i][i] = 0;
        a[i][i-1] = 1;
    }
    a[100][100] = 1;
    matrix c = powwmat(a,x+1);
   /* rep(i,0,3){
        rep(j,0,3) cout << c[i][j] << ' ';
        cout << c[i][100];
        cout << endl;
    }
    rep(i,0,3) cout << c[100][i] << ' ';
    cout << c[100][100] << endl;*/
    cout << c[0][100];
}