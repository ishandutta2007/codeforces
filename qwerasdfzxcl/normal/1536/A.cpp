#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
int a[10100];

void solve(){
    int n;
    scanf("%d", &n);
    bool flag = 0;
    for (int i=0;i<n;i++){
        scanf("%d", a+i);
        if (a[i]<0) flag = 1;
    }
    if (flag) printf("NO\n");
    else{
        printf("YES\n");
        printf("300 ");
        for (int i=0;i<300;i++) printf("%d ", i);
        printf("\n");
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