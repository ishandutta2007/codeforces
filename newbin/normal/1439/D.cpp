#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define lowbit(x) ((x)&(-(x)))
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
#define fors(i, a, b) for(int i = (a); i < (b); ++i)
using namespace std;
int mod;
int n, m;
const int maxn = 505;
int f[maxn], h[maxn], g[maxn][maxn], t[maxn][maxn];
int C[maxn][maxn];
int main()
{
    cin>>n>>m>>mod;
    C[0][0] = 1;
    fors(i,1,n+1){
        C[i][0] = 1;
        fors(j,1,i+1) {
            C[i][j] = (C[i-1][j] + C[i-1][j-1])%mod;
            //cout<<"i:"<<i<<" j:"<<j <<" C:"<<C[i][j]<<endl;
        }
    }
    f[0] = 1; h[0] = 0;
    fors(i,1,n+1){
        fors(j,0,i){
            f[i] = (f[i] + (ll)f[i-1-j]*f[j]%mod*(i+1)%mod*C[i-1][j]%mod)%mod;
        }
    }
    fors(i,1,n+1){
        fors(j,0,i){
            h[i] = (h[i] + (ll)f[j]*f[i-1-j]%mod*C[i-1][j]%mod*( (j+1)*j/2 + (i-1-j)*(i-j)/2 )%mod)%mod;
            h[i] = (h[i] + (ll)C[i-1][j]*(i+1)%mod*f[i-1-j]%mod*h[j]%mod)%mod;
            h[i] = (h[i] + (ll)C[i-1][j]*(i+1)%mod*f[j]%mod*h[i-1-j]%mod)%mod;
        }
    }
    g[0][0] = 1;
    fors(i,1,n+1){
        fors(j,0,i){
            g[i][j] = g[i-1][j];
            for(int l = 1; l <= j; ++l){
                g[i][j] = (g[i][j] + (ll)C[j][l] * g[i-1-l][j-l]%mod * g[l][l]%mod)%mod;
            }
        }
        g[i][i] = f[i];
    }
    fors(i,1,n+1){
        fors(j,0,i){
            t[i][j] = t[i-1][j];
            for(int l = 1; l <= j; ++l){
                t[i][j] = (t[i][j] + (ll)C[j][l] * t[i-1-l][j-l] % mod * f[l]%mod)%mod;
                t[i][j] = (t[i][j] + (ll)C[j][l] * h[l] % mod * g[i-1-l][j-l]%mod)%mod;
            }
        }
        t[i][i] = h[i];
    }
    cout<<t[n][m]<<endl;
}