#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
int r[200];
int b[200];
int rs[200];
int bs[200];

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n, m;
        scanf("%d", &n);
        for (int i=1;i<=n;i++) scanf("%d", r+i);
        scanf("%d", &m);
        for (int i=1;i<=m;i++) scanf("%d", b+i);
        rs[0]=0, bs[0]=0;
        int ans1=0, ans2=0;
        for (int i=1;i<=n;i++){
            rs[i]=rs[i-1]+r[i];
            ans1=max(ans1, rs[i]);
        }
        for (int i=1;i<=m;i++){
            bs[i]=bs[i-1]+b[i];
            ans2=max(ans2, bs[i]);
        }
        printf("%d\n", ans1+ans2);
    }
    return 0;
}