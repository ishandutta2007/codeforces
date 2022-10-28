#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define author rajat1603
#define getchar_unlocked getchar
using namespace std;
inline int scan(){
    char c = getchar_unlocked();
    int x = 0;
    while(c<'0'||c>'9'){
        c=getchar_unlocked();
    }
    while(c>='0'&&c<='9'){
        x=(x<<1)+(x<<3)+c-'0';
        c=getchar_unlocked();
    }
    return x;
}
const int N = 100;
const int M = 20;
const long long inf = 1110000004000000000LL;
int n,m,b;
int xx;
pair < int , pair < int , int > > arr[N];
long long dp[2][1<<M]={0};
int main(){
    n=scan(),m=scan(),b=scan();
    for(int i=0;i<n;++i){
        arr[i].second.first = scan();
        arr[i].first = scan();
        arr[i].second.second= 0;
        int temp = scan();
        while(temp--){
            arr[i].second.second|=(1<<scan()-1);
        }
    }
    for(int i=0;i<m;++i){
        xx|=(1<<i);
    }
    sort(arr,arr+n);
    for(int i=0;i<=xx;++i){
        dp[n&1][i]=inf;
    }
    dp[n&1][xx] = 1LL*arr[n-1].first * b;
    for(int i=n-1;i>=0;--i){
        for(int j=0;j<=xx;++j){
            if(j==xx){
                dp[i&1][j]=1LL*arr[i-1].first * b;
            }
            else
                dp[i&1][j] = min ( dp[!(i&1)][j] , dp[!(i&1)][j|arr[i].second.second]+ 1LL*arr[i].second.first);
        }
    }
    if(dp[0][0]>=inf){
        dp[0][0]=-1;
    }
    printf("%lld\n",dp[0][0]);
}