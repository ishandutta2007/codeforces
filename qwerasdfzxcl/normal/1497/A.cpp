#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
int a[100100];
bool chk[100100];

void solve(){
    int n;
    scanf("%d", &n);
    for (int i=0;i<n;i++) chk[i]=0;
    for (int i=0;i<n;i++) scanf("%d", a+i);
    sort(a, a+n);
    for (int i=1;i<n;i++){
        if (a[i]==a[i-1]) chk[i]=1;
    }
    for (int i=0;i<n;i++) if (!chk[i]) printf("%d ", a[i]);
    for (int i=0;i<n;i++) if (chk[i]) printf("%d ", a[i]);
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