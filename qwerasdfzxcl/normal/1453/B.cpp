#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
int a[200005];
int b[200005];

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        for (int i=0;i<n;i++) scanf("%d", a+i);
        ll ans1=0, ans2=0, ans3=0;
        for(int i=1;i<n;i++){
            ans1 += abs(a[i]-a[i-1]);
        }
        ll tmp=2147483647;
        for (int i=2;i<n;i++) tmp=min((int)tmp, abs(a[i]-a[i-2])-abs(a[i]-a[i-1])-abs(a[i-1]-a[i-2]));
        if (tmp!=-2147483647)ans1 += tmp;
        for (int i=2;i<n;i++) ans2 += abs(a[i]-a[i-1]);
        for (int i=1;i<n-1;i++) ans3 += abs(a[i]-a[i-1]);
        printf("%lld\n", min(min(ans1, ans2), ans3));
    }
    return 0;
}