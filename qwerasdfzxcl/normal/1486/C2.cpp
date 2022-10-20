#include <bits/stdc++.h>

typedef long long ll;
using namespace std;


int main(){
    int n;
    scanf("%d", &n);
    int l=1, r=n;
    printf("? %d %d\n", l, r);
    fflush(stdout);
    int tmp;
    scanf("%d", &tmp);
    while(l<r){
        int tmp2;
        int m=(l+r)/2;
        if (tmp<=m && l<m){
            if (tmp<l) printf("? %d %d\n", tmp, m);
            else printf("? %d %d\n", l, m);
            fflush(stdout);
            scanf("%d", &tmp2);
            if (tmp==tmp2) r=m;
            else l=m+1;
            continue;
        }
        else if (tmp>=m+1 && m+1<r){
            if (tmp>r) printf("? %d %d\n", m+1, tmp);
            else printf("? %d %d\n", m+1, r);
            fflush(stdout);
            scanf("%d", &tmp2);
            if (tmp==tmp2) l=m+1;
            else r=m;
            continue;
        }
        else if (r-l==2){
            printf("? %d %d\n", l, r);
            fflush(stdout);
            scanf("%d", &tmp2);
            int tmp3;
            printf("? %d %d\n", l, l+1);
            fflush(stdout);
            scanf("%d", &tmp3);
            if (tmp2==r){
                if (tmp3==l) printf("! %d\n", l+1);
                else printf("! %d\n", l);
            }
            else{
                if (tmp2==tmp3){
                    if (tmp2==l) printf("! %d\n", l+1);
                    else printf("! %d\n", l);
                }
                else printf("! %d\n", r);
            }
            return 0;
        }
        else{
            assert(l==r-1);
            printf("? %d %d\n", l, r);
            fflush(stdout);
            scanf("%d", &tmp2);
            if (tmp2==l) printf("! %d\n", l+1);
            else printf("! %d\n", l);
            return 0;
        }
    }
    assert(l==r);
    printf("! %d\n", l);
    //fflush(stdout);
    return 0;
}