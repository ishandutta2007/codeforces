#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
int a[1000004];

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n, k;
        scanf("%d %d", &n, &k);
        for (int i=0;i<n*k;i++){
            scanf("%d", &a[i]);
        }
        ll sum=0;
        int x1=n*k-(n/2)-1, x2=0;
        //printf("test\n");
        while (x2<k){
            x2++;
            sum += a[x1];
            //printf("%d\n", a[x1]);
            x1 -= ((n/2)+1);
        }
        printf("%lld\n", sum);
    }
    return 0;
}