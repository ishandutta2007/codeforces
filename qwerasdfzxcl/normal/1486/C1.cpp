#include <bits/stdc++.h>

typedef long long ll;
using namespace std;


int main(){
    int n;
    scanf("%d", &n);
    int l=1, r=n;
    while(l<r){
        printf("? %d %d\n", l, r);
        fflush(stdout);
        int tmp, tmp2;
        scanf("%d", &tmp);
        int m=(l+r)/2;
        if (tmp<=m && l<m){
            printf("? %d %d\n", l, m);
            fflush(stdout);
            scanf("%d", &tmp2);
            if (tmp==tmp2) r=m;
            else l=m+1;
            continue;
        }
        else if (tmp>=m+1 && m+1<r){
            printf("? %d %d\n", m+1, r);
            fflush(stdout);
            scanf("%d", &tmp2);
            if (tmp==tmp2) l=m+1;
            else r=m;
            continue;
        }
        else if (tmp<=m) l=m+1;
        else r=m;
    }
    assert(l==r);
    printf("! %d\n", l);
    //fflush(stdout);
    return 0;
}