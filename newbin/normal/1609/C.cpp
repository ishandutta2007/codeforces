#include<bits/stdc++.h>
#define fors(i,a,b) for(int i = a; i < b; ++i)
#define ll long long
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
#define all(x) x.begin(),x.end()
#define pb push_back
using namespace std;
const int maxn = 1e6+5;
int h[maxn], pri[maxn], cnt;
void INIT(){
    fors(i,2,maxn){
        if(!h[i]) pri[cnt++] = i;
        for(int j = 0; j < cnt && i*pri[j] < maxn; ++j){
            h[i*pri[j]] = 1;
            if(i%pri[j] == 0) break;
        }
    }
}
int f[maxn], g[maxn];
int n, e;
int a[maxn];
void init(){
    scanf("%d%d", &n, &e);
    fors(i,1,n+1) scanf("%d", &a[i]), f[i] = 0, g[i] = 0;
}
void sol(){
    ll ans = 0;
    for(int i = n; i > 0; --i){
        if(a[i] == 1) {
            f[i] = 1;
            if(i+e <= n && f[i]) f[i] += f[i+e];
        }
    }
    for(int i = 1; i <= n; ++i){
        if(a[i] == 1){
            g[i] = 1;
            if(i-e > 0 && g[i]) g[i] += g[i-e]; 
        }
        if(a[i] > 1 && !h[a[i]]){
            ll res = 0;
            if(i+e <= n) res = f[i+e];
            ans += res;
            if(i-e > 0) ans += (ll)g[i-e]*(res+1);
        }
    }
    cout<<ans<<endl;
}
int main(){
    INIT();
    int T; cin>>T;
    while(T--){
        init();sol();
    }
    return 0;
}