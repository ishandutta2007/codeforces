#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
int a[10010], x[10010], y[10010];

int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i=2;i<=n;i++){
        printf("and 1 %d\n", i);
        fflush(stdout);
        scanf("%d", x+i);
        printf("or 1 %d\n", i);
        fflush(stdout);
        scanf("%d", y+i);
    }

    int tand, tor;
    printf("and 2 3\n");
    fflush(stdout);
    scanf("%d", &tand);
    printf("or 2 3\n");
    fflush(stdout);
    scanf("%d", &tor);
    for (int z=0;z<=30;z++){
        if (x[2]&(1<<z)){
            a[1] |= (1<<z);
        }
        else if (!(y[2]&(1<<z))){
            continue;
        }
        else if (x[3]&(1<<z)){
            a[1] |= (1<<z);
        }
        else if (!(y[3]&(1<<z))){
            continue;
        }
        else if (tand&(1<<z)){
            if (x[2]&(1<<z)) a[1] |= (1<<z);
        }
        else if (!(tor&(1<<z))){
            if (y[2]&(1<<z)) a[1] |= (1<<z);
        }
    }

    for (int z=0;z<=30;z++){
        for (int i=2;i<=n;i++){
            if (x[i]&(1<<z)){
                a[i] |= (1<<z);
            }
            else if (!(y[i]&(1<<z))){
                continue;
            }
            else a[i] |= (a[1]&(1<<z)) ^ (1<<z);
        }
    }
    sort(a+1, a+n+1);
    printf("finish %d\n", a[k]);
    fflush(stdout);
    return 0;
}