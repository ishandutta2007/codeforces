#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
int a[200002];
int c[200002]={0};

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        for (int i=0;i<n;i++) scanf("%d", &a[i]);
        bool test1=1;
        for (int i=0;i<n-1;i++){
            if (a[i]!=a[i+1]) test1=0;
        }
        for (int i=1;i<=n;i++) c[i]=0;
        if (test1) {
            printf("0\n");
            continue;
        }
        for (int i=0;i<n;i++) c[i]=0;
        c[a[0]]=1;
        for (int i=1;i<n;i++){
            if (a[i]!=a[i-1]){
                if (c[a[i]]==0) c[a[i]]=2;
                else c[a[i]]++;
            }
        }
        c[a[n-1]]--;
        int ans=987654321;
        for (int i=1;i<=n;i++) {
            if (c[i]) ans=min(ans, c[i]);
        }
        printf("%d\n", ans);
    }
    return 0;
}