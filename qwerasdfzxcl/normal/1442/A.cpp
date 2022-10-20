#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
ll n, a[100100];
ll b[30030];

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%lld", &n);
        for (int i=0;i<n;i++) scanf("%lld", a+i);
        int i=1;
        for (i=1;i<n;i++){
            if(a[i]>a[i-1]) break;
        }
        if (i==n){
            printf("YES\n");
            continue;
        }
        b[n-1]=0;
        int k=i;
        for (i=n-1;i>k;i--){
            if (a[i-1]>a[i]){
                b[i-1]=b[i]+(a[i-1]-a[i]);
            }
            else b[i-1]=b[i];
        }
        bool test=1;
        for (i=k;i<n;i++){
            if (a[i]<b[i]) test=0;
        }
        if (test && a[k-1]>=b[k]){
            printf("YES\n");
        }
        else printf("NO\n");
    }
    return 0;
}