#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
int a[300300], b[300300];
int n;

int check(int idx){
    if (idx<=0 || idx>=n-1) return 0;
    int ret=0;
    if (a[idx]<a[idx-1] && a[idx]<a[idx+1]) ret++;
    if (a[idx]>a[idx-1] && a[idx]>a[idx+1]) ret++;
    return ret;
}

int check2(int idx){
    return check(idx-1)+check(idx)+check(idx+1);
}

void solve(){
    scanf("%d", &n);
    for (int i=0;i<n;i++) scanf("%d", a+i);
    int ans1=0, ans2=0;
    for (int i=1;i<n-1;i++){
        if (a[i]<a[i-1] && a[i]<a[i+1]){
            ans1++;
            b[i]=1;
        }
        if (a[i]>a[i-1] && a[i]>a[i+1]){
            ans1++;
            b[i]=1;
        }
    }
    for (int i=0;i<n;i++){
        int c1=check2(i);
        int tmp=a[i];
        a[i]=1;
        ans2=max(c1-check2(i), ans2);
        if (i) a[i]=a[i-1];
        ans2=max(c1-check2(i), ans2);
        if(i<n-1) a[i]=a[i+1];
        ans2=max(c1-check2(i), ans2);
        a[i]=1000000000;
        ans2=max(c1-check2(i), ans2);
        a[i]=tmp;
    }
    printf("%d\n", ans1-ans2);
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}