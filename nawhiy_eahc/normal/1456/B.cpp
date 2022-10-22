#include <iostream>

using namespace std;
int a[100002];
int c[32];
int d[100002];
int main()
{
    int n;
    scanf("%d", &n);
    a[0] = 0;
    for(int i=1;i<=n;i++){
        scanf("%d", &a[i]);
    }
    int t = 0;
    bool poss = true;
    for(int i=1;i<=n;i++){
        if(a[i] < (1<<t)){
            c[t]++;
            if(c[t] >= 3){
                printf("1");
                return 0;
            }
            if(c[t] >= 2){
                poss = false;
            }
        }
        else{
            while(a[i] >= (1<<t)) t++;
            c[t]++;
        }
    }

    if(poss){
        printf("-1");
        return 0;
    }
    d[0] = 0;
    for(int i=1;i<=n;i++){
        d[i] = d[i-1]^a[i];
    }

    int result = 1000000;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            for(int k=j+1;k<=n;k++){
                if((d[j]^d[i-1]) > (d[k]^d[j])) result = min(result, k-i-1);
            }
        }
    }

    if(result == 1000000) printf("-1");
    else printf("%d", result);
}