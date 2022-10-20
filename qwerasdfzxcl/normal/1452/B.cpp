#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
ll a[100002];

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        ll n;
        scanf("%lld", &n);
        ll s=0, m=-12345, ans;
        for (int i=0;i<n;i++){
            scanf("%lld", &a[i]);
            s += a[i];
            m=max(m, a[i]);
        }
        if (s<=m*(n-1)) ans=(m*(n-1))-s;
        else if (s%(n-1)==0) ans=0;
        else ans=(s/(n-1)+1)*(n-1)-s;
        printf("%lld\n", ans);
    }
    return 0;
}