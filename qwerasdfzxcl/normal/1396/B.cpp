#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
int a[1010];

void solve(){
    int n;
    scanf("%d", &n);
    for (int i=0;i<n;i++) scanf("%d", a+i);
    if (n==1) printf("T\n");
    else{
        int tmp = *max_element(a, a+n);
        int S = 0;
        for (int i=0;i<n;i++) S += a[i];
        if (S-tmp<tmp) printf("T\n");
        else if (S&1) printf("T\n");
        else printf("HL\n");
    }
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}