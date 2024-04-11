#include <cstdio>
#include <algorithm>
#include <map>
#define tmp usable_plus][cnt
using namespace std;

int n,k;
int data[300010];

int diff[300010];
int sz;

int maxplus;

long long dp[5010][5010];
bool chk[5010][5010];

int workcnt;

long long work(int usable_plus,int cnt)
{
    if(chk[tmp]) return dp[tmp];
    chk[tmp]=true;
    int ind=n-1-sz*(k-cnt)-(maxplus-usable_plus);
    if(cnt==0) return dp[tmp]=((ind==-1)?0:(1LL<<50));
    if(ind-sz+1<0) return dp[tmp]=(1LL<<50);
    if(usable_plus && ind>=sz){
        return dp[tmp]=min(work(usable_plus-1,cnt-1)+1ll*data[ind]-data[ind-sz],work(usable_plus,cnt-1)+1ll*data[ind]-data[ind-sz+1]);
    }
    else return dp[tmp]=work(0,cnt-1)+data[ind]-data[ind-sz+1];
}

int main()
{
    //freopen("D:\\input.txt","r",stdin);
    scanf("%d%d",&n,&k);
    int i;
    for(i=0;i<n;++i) scanf("%d",data+i);
    sort(data,data+n);
    maxplus=max(0,n-n/k*k);
    sz=n/k;
    printf("%I64d\n",work(maxplus,k));
    return 0;
}