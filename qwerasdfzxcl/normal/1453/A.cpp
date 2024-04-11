#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
int a[100005]={0};
int b[100005]={0};

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        for (int i=0;i<101;i++){
            a[i]=0;
            b[i]=0;
        }
        int n, m;
        scanf("%d %d", &n, &m);
        for (int i=0;i<n;i++){
            int tmp;
            scanf("%d", &tmp);
            a[tmp]++;
        }
        for (int i=0;i<m;i++){
            int tmp;
            scanf("%d", &tmp);
            b[tmp]++;
        }
        ll ans=0;
        for (int i=0;i<101;i++){
            if (a[i]==1 && b[i]==1) ans++;
        }
        printf("%lld\n", ans);
    }
    return 0;
}