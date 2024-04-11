#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
int n, k;
int a[200200], dp[200200], x[200200], mx[200200];

bool solve(int val){
    bool ret=0;
    dp[0]=0;
    if (a[0]>=val) dp[0]=1;
    x[0]=-2*dp[0];mx[0]=x[0];
    for (int i=1;i<n;i++){
        dp[i]=dp[i-1];
        if (a[i]>=val) dp[i]++;
        x[i]=i-2*dp[i];
        mx[i]=max(x[i], mx[i-1]);
        if (i>=k && x[i]<=max(mx[i-k]-1, -2)) ret=1;
        else if (i==k-1 && x[i]<=-2) ret=1;
    }
    return ret;
}

int main(){
    scanf("%d %d", &n, &k);
    for (int i=0;i<n;i++){
        scanf("%d", a+i);
    }
    if (n==1){
        printf("%d\n", a[0]);
        return 0;
    }
    int l=1, r=n, ans=-1;
    while(l<=r){
        int m=(l+r)/2;
        if (solve(m)){
            ans=m;
            l=m+1;
        }
        else r=m-1;
    }
    assert(ans!=-1);
    printf("%d\n", ans);
    return 0;
}