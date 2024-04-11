#include "bits/stdc++.h"
using namespace std;
const int N = 1e6 + 6;
int n;
char str[N];
int cntu[N];
int cntd[N];
long long sumu[N];
long long sumd[N];
vector < int > u;
vector < int > d;
int main(){
    scanf("%d" , &n);
    scanf("%s" , str + 1);
    for(int i = 1 ; i <= n ; ++i){
        cntu[i] = cntu[i - 1];
        cntd[i] = cntd[i - 1];
        sumu[i] = sumu[i - 1];
        sumd[i] = sumd[i - 1];
        if(str[i] == 'U'){
            ++cntu[i];
            sumu[i] += i;
            u.emplace_back(i);
        }
        else{
            ++cntd[i];
            sumd[i] += i;
            d.emplace_back(i);
        }
    }
    for(int i = 1 ; i <= n ; ++i){
        long long ans = 0;
        if(str[i] == 'D'){
            if(cntu[i - 1] > cntd[n] - cntd[i]){
                //upar jaega
                int x = u[cntu[i - 1] - (cntd[n] - cntd[i] + 1)];
                ans += 2LL * (1LL * (cntu[i - 1] - cntu[x - 1]) * i - sumu[i - 1] + sumu[x - 1]);
                ans += 2LL * (sumd[n] - sumd[i] - 1LL * (cntd[n] - cntd[i]) * i);
                ans += n - i + 1;
            }
            else{
                //neeche jaega
                int x = d[cntd[i] - 1 + cntu[i - 1]];
                ans += 2LL * (sumd[x] - sumd[i] - 1LL * (cntd[x] - cntd[i]) * i);
                ans += 2LL * (1LL * cntu[i - 1] * i - sumu[i - 1]);
                ans += i;
            }
        }
        else{
            if(cntu[i - 1] >= cntd[n] - cntd[i]){
                //upar jaega
                int x = u[cntu[i - 1] - (cntd[n] - cntd[i])];
                ans += 2LL * (1LL * (cntu[i - 1] - cntu[x - 1]) * i - sumu[i - 1] + sumu[x - 1]);
                ans += 2LL * (sumd[n] - sumd[i] - 1LL * (cntd[n] - cntd[i]) * i);
                ans += n - i + 1;   
            }
            else{
                //neeche jaega
                int x = d[cntd[i] - 1 + cntu[i - 1] + 1];
                ans += 2LL * (sumd[x] - sumd[i] - 1LL * (cntd[x] - cntd[i]) * i);
                ans += 2LL * (1LL * cntu[i - 1] * i - sumu[i - 1]);
                ans += i;
            }
        }
        printf("%lld%c" , ans , " \n"[i == n]);
    }
}