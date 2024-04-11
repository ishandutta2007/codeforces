#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
int a[100100], dp1[100100], dp2[100100];

void solve(){
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++) scanf("%d", a+i);
    dp1[0]=1;
    for (int i=1;i<n;i++){
        if (a[i]>a[i-1]) dp1[i]=dp1[i-1]+1;
        else dp1[i]=1;
    }
    dp2[n-1]=1;
    for (int i=n-2;i>=0;i--){
        if (a[i]>a[i+1]) dp2[i]=dp2[i+1]+1;
        else dp2[i]=1;
    }
    int mx=1, ans=0;
    for (int i=0;i<n;i++) mx=max(mx, max(dp1[i], dp2[i]));
    int c=0;
    for (int i=0;i<n;i++) if (dp1[i]==mx || dp2[i]==mx) c++;
    if (c>=2){
        printf("0\n");
        return;
    }
    for (int i=0;i<n;i++) if (dp1[i]==mx && dp2[i]==mx){
        if (mx&1) ans++;
    }
    printf("%d\n", ans);
}

int main(){
    solve();
    return 0;
}