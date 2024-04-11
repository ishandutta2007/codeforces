#include<bits/stdc++.h>
#define ll long long
#define fors(i,a,b) for(int i = a; i < b; ++i)
#define pb push_back
#define all(a) a.begin(),a.end()
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
using namespace std;
int n, m;
const int maxn = 405;
char s[maxn][maxn];
void init(){
    cin>>n>>m;
    fors(i,1,n+1) scanf("%s", s[i]+1);
}
int sum[maxn][maxn];
int a[maxn], b[maxn];
int f(int x1, int y1, int x2, int y2){
    int ans = sum[x2][y2]-sum[x1-1][y2]-sum[x2][y1-1]+sum[x1-1][y1-1];
    return ans;
}
void sol(){
    fors(i,1,n+1){
        fors(j,1,m+1){
            sum[i][j] = (s[i][j]-'0')+sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
        }
    }
    int ans = n*m;
    for(int i = 1; i <= n; ++i){
        for(int j = i+4; j <= n; ++j){
            for(int k = 1; k <= m; ++k){
                b[k] = f(i+1,1, j-1, k) + 2*k - f(i,1,i,k) - f(j,1,j,k);
                a[k] = j-i-1 - f(i+1,k,j-1,k) + b[k-1];
            }
            for(int k = 1; k <= m; ++k){
                b[k] -= j-i-1 - f(i+1,k,j-1,k);
                if(k>1) b[k] = max(b[k], b[k-1]);
            }
            for(int k = 4; k <= m; ++k){
                ans = min(ans, a[k]-b[k-3]);
            }
        }
    }
    cout<<ans<<endl;
}
int main(){
    int T; cin>>T;
    while(T--){
        init();
        sol();
    }
    return 0;
}