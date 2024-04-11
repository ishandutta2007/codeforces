#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    int sqn = sqrt(n)+2;
    if (n<=10) sqn--;
    printf("? %d\n", 1);
    fflush(stdout);
    vector<ll> ret;
    ll tmp;
    scanf("%lld", &tmp);
    ret.push_back(tmp);
    int cur = 1;
    while(true){
        cur += sqn;
        while (cur>n) cur -= n;
        printf("? %d\n", cur);
        fflush(stdout);
        ll tmp;
        scanf("%lld", &tmp);
        if (tmp>ret.back()) break;
        ret.push_back(tmp);
    }
    int l = cur-sqn-1, r = cur+sqn;
    while (l<=0) l += n;
    vector<ll> ret2;
    printf("? %d\n", l);
    fflush(stdout);
    ll tmp2;
    scanf("%lld", &tmp2);
    ret2.push_back(tmp2);
    for (int i = l+1;;i++){
        while (i>n) i -=n;
        printf("? %d\n", i);
        fflush(stdout);
        ll tmp;
        scanf("%lld", &tmp);
        if (tmp>ret2.back()){
            printf("! %d\n", i);
            break;
        }
        ret2.push_back(tmp);
    }
    return 0;
}