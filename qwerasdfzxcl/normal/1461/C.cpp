#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
int a[100100];

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n, m;
        scanf("%d %d", &n, &m);
        for (int i=0;i<n;i++) scanf("%d", a+i);
        int k=n;
        bool test=0;
        for (int i=n-1;i>=0;i--){
            if (a[i]!=i+1){
                k=i+1;
                test=1;
                break;
            }
        }
        if (!test) k=0;
        double ans=1;
        for (int i=0;i<m;i++){
            int b;
            double c;
            scanf("%d %lf", &b, &c);
            if (b>=k){
                ans *= ((double)1-c);
            }
        }
        if (!test) ans=0;
        printf("%lf\n", (double)1-ans);
    }
    return 0;
}