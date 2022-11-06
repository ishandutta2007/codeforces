#include <cstdio>
#include <algorithm>
#define pos first
#define radius second

using namespace std;

typedef pair<int,int> pp;

pp data[100010];
int dp[100010];

int n;

int min(int a,int b){ return a>b?b:a; }

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;++i) scanf("%d%d",&data[i].pos, &data[i].radius);
    sort(data,data+n);
    int pos,radius;
    int ans=1e9;
    for(int i=0;i<n;++i){
        pos=data[i].pos; radius=data[i].radius;
        if(pos-radius<=data[0].pos){
            dp[i]=i;
        } else {
            int ub = upper_bound(data,data+n,pp(pos-radius,0))-data;
            dp[i]=(i-ub) + dp[ub-1];
        }
        ans=min(ans,dp[i]+n-i-1);
    }
    printf("%d\n",ans);
    return 0;
}