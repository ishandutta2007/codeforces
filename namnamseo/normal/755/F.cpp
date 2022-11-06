#include <bits/stdc++.h>
using namespace std;
void read(int& x){ scanf("%d",&x); }
template<typename T,typename... Args>
void read(T& a,Args&... b){ read(a); read(b...); }
#define pb push_back
#define all(x) (x).begin(),(x).end()

const int max_n = int(1e6) + 10;

int n, k;
int nxt[max_n];
int vis[max_n];
int cnt[max_n];

bitset<max_n> dp;

int main()
{
    read(n, k);
    for(int i=1; i<=n; ++i) read(nxt[i]);
    vector<int> cs;
    for(int i=1; i<=n; ++i) if(!vis[i]){
        int r=1;
        vis[i]=1;
        for(int j=nxt[i]; j!=i; j=nxt[j]){
            ++r;
            vis[j]=1;
        }
        cs.pb(r);
        ++cnt[r];
    }
    sort(all(cs));
    dp[0]=1;
    for(int i=1; i<=n; ++i){
        if(!cnt[i]) continue;
        for(int j=0; j<=20; ++j){
            if((1<<j) <= cnt[i])
                dp |= (dp << (i*(1<<j))),
                cnt[i] -= (1<<j);
        }
        if(cnt[i]) dp |= (dp << (i*cnt[i]));
    }
    printf("%d ", k+1-dp[k]);
    int mc=0;
    for(int x:cs) mc+=x/2;
    if(k <= mc){
        printf("%d\n", k*2);
    } else {
        printf("%d\n", min(n, k+mc));
    }
    return 0;
}