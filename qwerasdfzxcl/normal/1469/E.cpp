#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
char str[1001000];
pair<bool, int> check[(1<<23)];
int suf[1001000];
int dp[1001000];

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n, k;
        scanf("%d %d", &n, &k);
        scanf("%s", str);
        suf[0]=str[0]-'0';
        dp[0]=suf[0];
        if (k==1) check[dp[0]]=make_pair(1, t);
        for (int i=1;i<n;i++){
            if (str[i]=='1') suf[i]=suf[i-1]+1;
            else suf[i]=0;
            int tmp;
            if (k>22)tmp=dp[i-1]&(~(1<<21));
            else tmp=dp[i-1]&(~(1<<(k-1)));
            tmp <<=1;
            tmp+=(str[i]-'0');
            dp[i]=tmp;
            //printf("dp %d: %d\n", i, tmp);
            if (i<k-1) continue;
            if (k>21){
                if (suf[i-22]>=k-22){
                    check[dp[i]].first=1;
                    check[dp[i]].second=t;
                }
            }
            else{
                check[dp[i]].first=1;
                check[dp[i]].second=t;
            }
        }
        int xx=min(22, k);
        int anss;
        bool test=1;
        for (int i=(1<<xx)-1;i>=0;i--){
            if (!check[i].first || check[i].second!=t){
                test=0;
                anss=i;
                break;
            }
        }
        if (test) printf("NO\n");
        else{
            printf("YES\n");
            int yy=max(0, k-22);
            for (int i=0;i<yy;i++) printf("0");
            for (int i=xx-1;i>=0;i--){
                if (anss & (1<<i)) printf("0");
                else printf("1");
            }
            printf("\n");
        }
    }
    return 0;
}