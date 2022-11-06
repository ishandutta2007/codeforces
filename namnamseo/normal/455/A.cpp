#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;
void read(int& a){ scanf("%d",&a); }
template<typename T,typename... Args> void read(T& a,Args&... b){ read(a); read(b...); }
int n;
int data[100010];
typedef long long ll;
ll dp[100010][2];
map<int,int> cnt;
int main()
{
    read(n);
    int i;
    for(i=1;i<=n;++i) read(data[i]), ++cnt[data[i]];
    sort(data+1,data+n+1);
    n=unique(data+1,data+n+1)-data-1;
    dp[0][1]=-(1LL<<62);
    int mul;
    data[0]=-(1LL<<30);
    for(i=1;i<=n;++i){
        dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
        mul=cnt[data[i]];
        dp[i][1]=dp[i-1][0]+mul*1LL*data[i];
        if(data[i]!=data[i-1]+1){
            dp[i][1]=max(dp[i][1], dp[i-1][1]+mul*1LL*data[i]);
        }
        //printf("%d %d %I64d %I64d\n",data[i],mul,dp[i][0],dp[i][1]);
    }
    printf("%I64d\n",max(dp[n][0],dp[n][1]));
    return 0;
}