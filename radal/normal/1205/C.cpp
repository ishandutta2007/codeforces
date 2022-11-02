#include <bits/stdc++.h>
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("unroll-loops")
#define rep(i,l,r) for (int i = l; i < r; i++)
#define repr(i,r,l) for (int i = r; i >= l; i--)
#define X first
#define Y second
#define pb push_back
#define endl '\n'
#define debug(x) cerr << #x << " : " << x << endl;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pll;
constexpr int N = 50+20,mod = 1e9+7,inf = 1e9+10,maxm = (1 << 20);
inline int mkay(int a,int b){
    if (a+b >= mod) return a+b-mod;
    if (a+b < 0) return a+b+mod;
    return a+b;
}
 
inline int poww(int a,int k){
    if (k < 0) return 0;
    int z = 1;
    while (k){
        if (k&1) z = 1ll*z*a%mod;
        a = 1ll*a*a%mod;
        k >>= 1;
    }
    return z;
}
int a[N][N],n,b;
inline void ch(int x1,int y1,int x2,int y2){
    cout << "? " << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << endl;
    cin >> b;
    return;
}
inline void out(bool f){
    cout << '!' << endl;
    rep(i,1,n+1){
        rep(j,1,n+1){
            if (((i+j)&1)){
                if (f) cout << a[i][j];
                else cout << 1-a[i][j];
            }
            else
                cout << a[i][j];
        }
        cout << endl;
    }
}
int main(){
    cin >> n;
    a[1][1] = 1;
    for (int i = 1; i <= n; i += 2){
        for(int j = 1; j < n; j += 2){
            ch(i,j,i,j+2);
            if (b) a[i][j+2] = a[i][j];
            else a[i][j+2] = 1-a[i][j];
        }
        if (i < n){
            ch(i,1,i+2,1); 
            if (b) a[i+2][1] = a[i][1];
            else a[i+2][1] = 1-a[i][1];
        }
    }
    ch(1,1,2,2);
    if (b) a[2][2] = 1;
    else a[2][2] = 0;
    for (int i = 2; i <= n; i += 2){
        for (int j = 2; j+1 < n; j += 2){
            ch(i,j,i,j+2);
            if (b) a[i][j+2] = a[i][j];
            else a[i][j+2] = 1-a[i][j];
        }
        if (i+1 < n){
            ch(i,2,i+2,2);
            if (b) a[i+2][2] = a[i][2];
            else a[i+2][2] = 1-a[i][2];
        }
    }
    for (int i = 1; i <= n; i += 2){
        for (int j = 2; j+1 < n; j += 2){
            ch(i,j,i,j+2);
            if (b) a[i][j+2] = a[i][j];
            else a[i][j+2] = 1-a[i][j];
        }
        if (i < n){
            ch(i,2,i+2,2);
            if (b) a[i+2][2] = a[i][2];
            else a[i+2][2] = 1-a[i][2];
        }
    }
    ch(1,2,2,3);
    if (b) a[2][3] = 0;
    else a[2][3] = 1;
    ch(2,1,2,3);
    if (b) a[2][1] = a[2][3];
    else a[2][1] = 1-a[2][3];
    for (int i = 2; i <= n; i += 2){
        for (int j = 1; j < n; j += 2){
            if (i == 2 && j == 1) continue;
            ch(i,j,i,j+2);
            if (b) a[i][j+2] = a[i][j];
            else a[i][j+2] = 1-a[i][j];
        }
        if (i+1 < n){
            ch(i,1,i+2,1);
            if (b) a[i+2][1] = a[i][1];
            else a[i+2][1] = 1-a[i][1];
        }
    }
    int k = -1;
    bool f;
    rep(i,2,n){
        if (a[i][i] && a[i-1][i-1] && a[i][i] != a[i+1][i+1]){
            k = i;
            break;
        }
    }
    if (k != -1){
        ch(k-1,k,k+1,k+1);
        if (a[k][k+1] != a[k+1][k]){
            if ((b && a[k-1][k] == a[k+1][k+1]) || (!b && a[k-1][k] != a[k+1][k+1])) f = 1;
            else f = 0;
            out(f);
            return 0;
        }
        if (b){
            if (a[k-1][k] == a[k+1][k+1]) f = 1;
            else f = 0;
            out(f);
            return 0;
        }
        if (a[k-1][k] != a[k][k+1]){
            f = a[k-1][k];
            out(f);
            return 0;
        }
        ch(k-1,k-1,k,k+1);
        if (b){
            f = a[k-1][k];
            out(f);
            return 0;
        }
        f = 1-a[k-1][k];
        out(f);
        return 0;
    }
    rep(i,2,n){
        if (!a[i][i] && !a[i+1][i+1] && a[i-1][i-1]){
            k= i;
            break;
        }
    }
    if (k != -1){
        ch(k-1,k-1,k+1,k);
        if (a[k][k-1] != a[k-1][k]){
            if ((b && a[k-1][k-1] == a[k+1][k]) || (!b && a[k-1][k-1] != a[k+1][k])) f = 1;
            else f = 0;
            out(f);
            return 0;
        }
        if (b){
            if (a[k-1][k-1] == a[k+1][k]) f = 1;
            else f = 0;
            out(f);
            return 0;
        }
        if (a[k-1][k] != a[k+1][k]){
            f = 1-a[k+1][k];
            out(f);
            return 0;
        }
        ch(k-1,k,k+1,k+1);
        if (!b){
            f = a[k-1][k];
            out(f);
            return 0;
        }
        f = 1-a[k-1][k];
        out(f);
        return 0;
    }

}