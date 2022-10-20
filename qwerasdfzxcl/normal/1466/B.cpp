#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
int a[100100];

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        for (int i=0;i<n;i++) scanf("%d", a+i);
        for (int i=1;i<n;i++){
            if (a[i-1]>=a[i]) a[i]++;
        }
        int ans=1;
        for (int i=1;i<n;i++){
            if (a[i-1]!=a[i]) ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}