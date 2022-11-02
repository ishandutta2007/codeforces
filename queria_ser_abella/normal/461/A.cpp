#include <bits/stdc++.h>
#define maxn 300300
#define ll long long
using namespace std;

int v[maxn];

int main() {
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",v+i);
    sort(v,v+n);
    ll ans = 0;
    if(n == 1)
        ans = v[0];
    else
        for(int i=0;i<n;i++){
            if(i < n-1)
                ans += (ll) (i+2) * v[i];
            else
                ans += (ll) n * v[i];
        }
    printf("%lld\n",ans);
}