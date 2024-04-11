#include <bits/stdc++.h>
#define maxn 200200
#define pb push_back
#define debug
typedef long long ll;
using namespace std;

int a[maxn];
int b[maxn];

main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d%d",a+i,b+i);
    sort(a,a+n);
    sort(b,b+n);
    ll ans = 0;
    for(int i=0;i<n;i++)
        ans += max(a[i],b[i]);
    printf("%lld\n",ans+n);
}