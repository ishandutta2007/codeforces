#include <cstdio>
#include <vector>

using namespace std;

int dat[2010];

int dp[2010][2010];

int n;

int abs(int x){ return x>0?x:-x; }

int max(int a,int b){ return a>b?a:b; }
int min(int a,int b){ return a<b?a:b; }

int main()
{
    int i,j;
    scanf("%d",&n);
    vector<int> cur, miv;
    int buf;
    for(i=1;i<=n;++i) scanf("%d",&buf),cur.push_back(abs(buf));
    int mv, ms;
    int ans=0;
    while((n=cur.size())){
        mv=-1;
        for(i=0;i<n;++i) mv=max(mv,cur[i]);
        for(i=0;i<n;++i) if(cur[i]==mv) miv.push_back(i);
        ms=miv.size();
        for(i=1;i<=ms;++i){
            for(j=0;j<=i;++j){
                // left : there are total (miv[i-1]+1) points, and i max(and j positive), (miv[i-1]-i+1) notmax
                // right : there are total (n-miv[i-1]-1) points, and (ms-i) max, (n-miv[i-1]-1-ms+i) notmax
                dp[i][j]=2e9;
                if(j){
                    dp[i][j]=min(dp[i][j],dp[i-1][j-1]+miv[i-1]-i+1+i-j);
                }
                if(j!=i) dp[i][j]=min(dp[i][j],dp[i-1][j]+n-miv[i-1]-1-ms+i);
                //printf("%d, %d : %d\n",i,j,dp[i][j]);
            }
        }
        int ca=2e9;
        for(i=0;i<=ms;++i) ca=min(ca,dp[ms][i]); ans+=ca;
        //printf("ca %d\n",ca);
        miv.clear();
        for(i=0;i<n;++i) if(cur[i]!=mv) miv.push_back(cur[i]);
        ms=miv.size();
        cur.clear();
        for(i=0;i<ms;++i) cur.push_back(miv[i]);
        miv.clear();
    }
    printf("%d\n",ans);
    return 0;
}