#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
ll a[1001000];
bool poss[1001000];

int main(){
    ll k, l, r, t, x, y;
    scanf("%lld %lld %lld %lld %lld %lld", &k, &l, &r, &t, &x, &y);
    if (x<y){
        ll tmp=l;
        for (int i=0;i<x;i++){
            if (tmp-x>=l) tmp -= x;
            a[tmp%x]=tmp;
            tmp++;
        }
        bool test=1;
        for (int i=0;i<x;i++){
            if(a[i]+y>r){
                poss[i]=0;
                test=0;
            }
            else poss[i]=1;
            //printf("%d %d %d\n", i, a[i], poss[i]);
        }
        if (test){
            printf("Yes");
            return 0;
        }
        ll c=0, tmp1=k%x;
        bool test1=1;
        for (c=0;c<x;c++){
            if (!poss[tmp1]){
                test1=0;
                break;
            }
            tmp1 =(tmp1+y)%x;
        }
        if (test1){
            printf("Yes");
            return 0;
        }
        k += (c*y);
        ll tmax=(k-a[k%x])/x;
        if (tmax>=t) printf("Yes");
        else printf("No");
    }
    else if (x==y){
        if (k+y<=r){
            printf("Yes");
            return 0;
        }
        if (k-x<l){
            printf("No");
        }
        else printf("Yes");
    }
    else{
        if (k+y<=r) k += y;
        k -= x;
        if (k<l){
            printf("No");
            return 0;
        }
        ll tmp2=1;
        tmp2 += (k-l)/(x-y);
        if (tmp2>=t) printf("Yes");
        else printf("No");
    }
    return 0;
}