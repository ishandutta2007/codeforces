#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
pair<int, int> a[200002];

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        for (int i=1;i<=n;i++){
            int tmp;
            scanf("%d", &tmp);
            a[i-1]=make_pair(tmp, i);
        }
        sort(a, a+n);
        bool test=0;
        if (n==1){
            printf("1\n");
            continue;
        }
        if (a[0].first!=a[1].first){
            printf("%d\n", a[0].second);
            continue;
        }
        for (int i=1;i<n-1;i++){
            if (a[i-1].first==a[i].first) continue;
            if (a[i].first!=a[i+1].first){
                test=1;
                printf("%d\n", a[i].second);
                break;
            }
        }
        if (test) continue;
        if (a[n-2].first!=a[n-1].first){
            printf("%d\n", a[n-1].second);
            continue;
        }
        printf("-1\n");
    }
    return 0;
}