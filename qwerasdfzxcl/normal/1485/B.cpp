#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
int a[100100];
int c[100100];
ll s[100100];

int main(){
    int n, q, k;
    scanf("%d %d %d", &n, &q, &k);
    for (int i=0;i<n;i++) scanf("%d", a+i);
    c[0]=a[1]-1;
    for (int i=1;i<n-1;i++){
        c[i]=a[i+1]-a[i-1]-1;
    }
    c[n-1]=k-a[n-2];
    s[0]=c[0];
    for (int i=1;i<n;i++) s[i]=s[i-1]+c[i];
    while(q--){
        int l, r;
        scanf("%d %d", &l, &r);
        l--, r--;
        if (l==r){
            printf("%d\n", k-1);
            continue;
        }
        ll ans=0;
        ans += a[l+1]-1;
        ans += k-a[r-1];
        ans += s[r-1]-s[l];
        printf("%lld\n", ans-(r-l+1));
    }
    return 0;
}