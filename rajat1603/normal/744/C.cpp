#include "bits/stdc++.h"
using namespace std;
const int N = 20;
int n;
char str[N];
int a[N];
int b[N];
map < int , int > dp[5 + (1 << 17)][2];
int solve(int mask , int asum , int bsum , int cnt , int ac , int bc , int mema , int memb){
    if(cnt >= n){
        return 0;
    }
    if(asum){
        if(dp[mask][0].find(asum) != dp[mask][0].end()){
            return dp[mask][0][asum];
        }
    }
    else{
        if(dp[mask][1].find(bsum) != dp[mask][1].end()){
            return dp[mask][1][bsum];
        }
    }
    int res = 1e9;
    for(int i = 1 ; i <= n ; ++i){
        if(!(mask & (1 << i))){
            int acst = a[i] - ac;
            int bcst = b[i] - bc;
            int req = max(0 , max(acst - asum , bcst - bsum));
            int nasum = asum + req - max(0 , acst);
            int nbsum = bsum + req - max(0 , bcst);
            res = min(res , 1 + req + solve(mask | (1 << i) , nasum , nbsum , cnt + 1 , ac + (str[i] == 'R') , bc + (str[i] == 'B') , mema + min(ac , a[i]) , memb + min(bc , b[i])));
        }
    }
    if(asum){
        dp[mask][0][asum] = res;
    }
    else{
        dp[mask][1][bsum] = res;
    }
    return res;
}
char tmp[5];
int main(){
    scanf("%d" , &n);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%s" , tmp);
        str[i] = tmp[0];
        scanf("%d %d" , a + i , b + i);
    }
    printf("%d\n" , solve(0 , 0 , 0 , 0 , 0 , 0 , 0 , 0));
}