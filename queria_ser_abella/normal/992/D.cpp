#include <bits/stdc++.h>
#define maxn 300300
#define pb push_back
#define pii pair<int,int>
#define ll long long
using namespace std;

int k;

int bad;

int v[maxn];
int nxt[maxn];

ll mul(ll a,ll b){
    bad = 0;
    if(log(a) + log(b) > log(3) + 18*log(10)) bad = 1;
    return a*b;
}

int good(ll pi,int s){
    if(pi%s == 0 && pi/s == k)
        return 1;
    return 0;
}

int main() {
    int n;
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++)
        scanf("%d",v+i);
    nxt[n-1] = n;
    for(int i=n-2;i>=0;i--){
        if(v[i+1] != 1)
            nxt[i] = i+1;
        else
            nxt[i] = nxt[i+1];
    }
    ll ans = 0;
    for(int i=0;i<n;i++){
        ll pi = 1, s = 0;
        int j = i;
        while(1){
            pi = mul(pi,v[j]);
            if(bad) break;
            s += v[j];
            if(good(pi,s)) ans++;
            int jj = nxt[j];
            
            int qt = jj-j-1;
            if(pi%k == 0){
                int need = (pi/k)-s;
                if(need > 0 && need <= qt) ans++;
            }
            if(jj >= n) break;
            s += qt;
            j = jj;
        }
    }
    printf("%lld\n",ans);
}