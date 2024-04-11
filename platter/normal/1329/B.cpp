#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int tc;
    scanf("%d\n",&tc);
    for(int t=0;t<tc;t++) {
        long long d,m;
        scanf("%lld %lld\n",&d,&m);
        vector<long long> v;
        long long val=1;
        while (1) {
            if (d<val) {
                v.push_back(d-val/2+1);
                break;
            }
            else {
                v.push_back(val/2);
                val*=2;
            }
        }
        long long ret=1%m;
        for(int i=0;i<v.size();i++) {
            ret*=v[i]+1;
            ret%=m;
        }
        ret+=m-1;
        ret%=m;
        printf("%lld\n",ret);
    }
}