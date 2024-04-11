#include <bits/stdc++.h>
#define pii pair<ll,ll>
#define pb push_back
#define maxn 300300
#define ll long long
#define debug
using namespace std;

ll a[2*maxn];

main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<2*n;i++)
        scanf("%lld",a+i);
    sort(a,a+2*n);
    ll ans = (a[n-1] - a[0]) * (a[2*n-1] - a[n]);
    for(int i=1;i<n;i++){
        ans = min(ans,(a[2*n-1]-a[0]) * (a[i+n-1] - a[i]));
    }
    printf("%lld\n",ans);
}