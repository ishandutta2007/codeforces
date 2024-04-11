#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    int t; scanf("%d", &t);
    while(t--){
        int n, k;
        scanf("%d %d", &n, &k);
        if(k%2 == 0){
            printf("%d\n", n - k + k/2);
            for(int i=k/2;i<k;i++) printf("%d ", i);
            for(int i=k+1;i<=n;i++) printf("%d ", i);
            printf("\n");
        }
        else{
            printf("%d\n", n - k + k/2);
            for(int i=k/2+1;i<k;i++) printf("%d ", i);
            for(int i=k+1;i<=n;i++) printf("%d ", i);
            printf("\n");
        }
    }
}