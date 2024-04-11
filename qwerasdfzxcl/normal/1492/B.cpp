#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
int a[100100], b[100100];

void solve(){
    int n;
    scanf("%d", &n);
    for (int i=0;i<n;i++) scanf("%d", a+i);
    int val=-1;
    for (int i=0;i<n;i++){
        if (val<a[i]) b[i]=i;
        else b[i]=b[i-1];
        val=max(val, a[i]);
    }
    int prev=n;
    for (int i=b[n-1];i>0;i=b[i-1]){
        for (int j=i;j<prev;j++) printf("%d ", a[j]);
        prev=i;
    }
    for (int j=0;j<prev;j++) printf("%d ", a[j]);
    printf("\n");
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}