#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
int a[100100], q[100100], n;

int query(){
    printf("? ");
    for (int i=0;i<n;i++) printf("%d ", q[i]);
    printf("\n");
    fflush(stdout);
    int ret;
    scanf("%d", &ret);
    return ret;
}

int main(){
    scanf("%d", &n);
    fill(q, q+n, n);
    q[n-1] = 1;
    a[n-1] = 1;
    for (int i=n;i>=2;i--){
        int tmp = query();
        if (tmp){a[n-1] = i; break;}
        fill(q, q+n-1, i-1);
    }

    for (int i=1;i<=n;i++) if (i!=a[n-1]){
        if (i>a[n-1]){
            q[n-1] = n;
            fill(q, q+n-1, n+a[n-1]-i);
        }
        else{
            q[n-1] = n+i-a[n-1];
            fill(q, q+n-1, n);
        }
        int tmp = query();
        a[tmp-1] = i;
    }

    printf("! ");
    for (int i=0;i<n;i++) printf("%d ", a[i]);
    printf("\n");
    fflush(stdout);
    return 0;
}