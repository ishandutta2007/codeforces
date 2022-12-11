#include<bits/stdc++.h>
#define fors(i,a,b) for(int i = a; i < b; ++i)
#define ll long long
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
#define all(x) x.begin(),x.end()
#define pb push_back
using namespace std;
const int maxn = 1e5+5;
ll a[maxn], x;
ll b[maxn];
ll st[maxn][20];
int len[maxn];
int f[maxn][2];
int main(){
    int T; cin>>T;
    while(T--){
        int n; scanf("%d", &n);
        fors(i,1,n+1) scanf("%lld", &a[i]), a[i] += a[i-1];
        scanf("%lld", &x);
        b[0] = 0;
        for(int i = 1; i <= n; ++i){
            b[i] = a[i]-x*i;
            st[i][0] = b[i];
        }
        for(int j = 1; j < 20; ++j){
            for(int i = 0; i+(1<<j)-1 <= n; ++i){
                st[i][j] = max(st[i][j-1], st[i+(1<<(j-1))][j-1]);
            }
        }
        // cout<<"?"<<endl;
        len[0] = 0;
        len[1] = 1;
        for(int i = 2; i <= n; ++i){
            int p = i-2;
            if(b[p] > b[i]){
                len[i] = 1; continue;
            }
            for(int j = 19; j >= 0 ; j--) 
                if(p-(1<<j) >= 0 && st[p-(1<<j)][j] <= b[i]) p -= 1<<j;
            len[i] = i-p;
            len[i] = min(len[i], len[i-1]+1);
        }
        for(int i = 1; i <= n; ++i){
            // cout<<"i:"<<i<<" len:"<<len[i]<<" b:"<<b[i]<<endl;
            f[i][0] = max(f[i-1][1], f[i-1][0]);
            if(len[i] > 0) f[i][1] = f[ i-len[i] ][0] + len[i];
        }
        int ans = max(f[n][0], f[n][1]);
        cout<<ans<<endl;
    }
    return 0;
}