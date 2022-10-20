#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
int a[100100], prime[20020];

void solve(){
    int n;
    scanf("%d", &n);
    int S = 0;
    for (int i=0;i<n;i++){
        scanf("%d", a+i);
        S += a[i];
    }
    if (!prime[S]){
        printf("%d\n", n);
        for (int i=0;i<n;i++){
            printf("%d ", i+1);
        }
        printf("\n");
    }
    else{
        int idx = -1;
        for (int i=0;i<n;i++) if (a[i]&1) {idx = i; break;}
        assert(idx!=-1);
        printf("%d\n", n-1);
        for (int i=0;i<n;i++) if (i!=idx) printf("%d ", i+1);
        printf("\n");
    }
}

int main(){
    fill(prime+2, prime+20020, 1);
    for (int i=2;i<20020;i++){
        if (!prime[i]) continue;
        for (int j=2;i*j<20020;j++) prime[i*j] = 0;
    }
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}