#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <functional>

#define mp make_pair
#define pb push_back
#define mes(a,b) memset(a,b,sizeof(a))
#define mes0(a) memset(a,0,sizeof(a))
#define lson l,mid,pos<<1
#define rson mid+1,r,pos<<1|1
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define fi first
#define se second
#define sss(a) a::iterator
#define all(a) a.begin(),a.end()

using namespace std;

typedef double DB;
typedef long long LL;
typedef pair<int,int> pii;
typedef pair<long long ,int> pli;
typedef pair<int,long long > pil;
typedef pair<string,int> psi;
typedef pair<long long ,long long > pll;

const int inf = 0x3f3f3f3f;
const long long INF = 0x3f3f3f3f3f3f3f3f;
const double pi = acos(-1.0);
const int maxn = 100000+10;
const int mod = 1e9+7;
LL dp[500][500];
LL C[500][500];
LL fact[500];
int cnt[500];
int a[500];
int vis[500];
int sz;
int check(LL x)
{
    LL l=1,r=1e9;
    LL now=l;
    while (l<=r){
        LL mid=(l+r)>>1;
        if (mid*mid<=x)now=mid,l=mid+1;
        else r=mid-1;
    }
    return now*now==x;
}
inline LL M(LL x)
{
    return x%mod;
}
void init()
{
    C[0][0]=1;
    fact[0]=1;
    for (int i=1;i<=300;i++){
        C[i][0]=1;
        for (int j=1;j<=i;j++){
            C[i][j]=M(C[i-1][j]+C[i-1][j-1]);
        }
    }
    for (int i=1;i<=300;i++)fact[i]=M(fact[i-1]*i);
}
void slove()
{
    dp[0][cnt[0]-1]=1;
    int lim=cnt[0];
    for (int i=1;i<sz;i++){
        for (int j=0;j<lim;j++){  /// dp[i-1][j]
            for (int k=0;k<cnt[i];k++){/// group[i]k+1 ,cnt[i]-1-k
                for (int m=0;m<=min(j,k+1);m++){ /// m
                    dp[i][j+cnt[i]-1-k-m]=M(dp[i][j+cnt[i]-1-k-m]+dp[i-1][j]*C[cnt[i]-1][k]%mod*C[j][m]%mod*C[lim-1-j+2][k+1-m]);
                }
            }
        }
        lim+=cnt[i];
    }
    LL ans=dp[sz-1][0];
    for (int i=0;i<sz;i++){
        ans*=fact[cnt[i]];
        ans%=mod;
    }
    cout<<ans<<endl;
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        scanf("%d",a+i);
    }
    for (int i=0;i<n;i++){
        if (vis[i]==0){
            for (int j=i;j<n;j++){
                if (check(1LL*a[i]*a[j])){
                    cnt[sz]++;
                    vis[j]=1;
                }
            }
            sz++;
        }
    }
    init();
    slove();
    return 0;
}