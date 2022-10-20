#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
int a[100];
bool check[100];

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        for (int i=0;i<n;i++) scanf("%d", a+i);
        for (int i=1;i<=50;i++) check[i]=0;
        for (int i=0;i<n-1;i++){
            for (int j=i+1;j<n;j++) check[abs(a[i]-a[j])]=1;
        }
        int ans=0;
        for (int i=1;i<=50;i++) if (check[i]) ans++;
        printf("%d\n", ans);
    }
    return 0;
}