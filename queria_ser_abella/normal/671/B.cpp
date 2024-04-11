#include <bits/stdc++.h>
#define maxn 600600
#define debug 
typedef long long ll;
using namespace std;

ll v[maxn];

ll mn(int i,int j,ll g,int k){
    for(int a=i;a<=j;a++)
        debug("%d ",v[a]);
        debug("\n");
    for(int a=j;a>=i+1;a--){
        if((j-a+1) * (v[a]-v[a-1]) > k){
            debug("%d * %lld > %d\n",j-a+1,(v[a]-v[a-1]) , k);
            debug("ret %lld - %d / %d\n",v[a],k,j-a+1);
            return v[a] - k / (j-a+1);
        }
        k -= (j-a+1) * (v[a]-v[a-1]);
    }debug("OI\n");
    return max(g, v[i] - k / (j-i+1));
}

int main() {
    int n,k;
    ll s = 0, t = 0;
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++)
        scanf("%lld",v+i), s += v[i];
    sort(v,v+n);
    ll d = s/n;
    for(int i=0;i<n;i++)
        t += abs(v[i]-d);
    int u = 0;
    while(u < n-1 && v[u+1] <= d){
        v[u] = -v[u];
        u++;
    }
    if(u == n-1){
        printf("0\n");
        return 0;
    }
    v[u] = -v[u];
    for(int i=0;2*i<u;i++)
        swap(v[i],v[u-i]);
    ll a = mn(0,u,-d,k);
    ll b = mn(u+1,n-1,d,k);
    if(a + b == 0){
        if(s%n){
            printf("1\n");
            return 0;
        }
        t /= 2;
        debug("%d %d\n",k,t);
        if(k > t && (k-t)%2 == 1)
            printf("0\n");
        else
            printf("0\n");
    }
    else printf("%lld\n",a+b);
}