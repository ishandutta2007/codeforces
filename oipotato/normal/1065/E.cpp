#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<iostream>
#include<cassert>
#include<set>
#include<stack>
using namespace std;
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=1;i<=n;i++)
const int MOD=998244353;
const int rev2=499122177;
int n,m,A,ans,b[200010];
int mypow(int x,int n){int ans=1;for(;n;n>>=1,x=1ll*x*x%MOD)if(n&1)ans=1ll*ans*x%MOD;return ans;}
int cal_cnt(int len){return 1ll*(mypow(A,2*len)+mypow(A,len))*rev2%MOD;}
int main()
{
    scanf("%d%d%d",&n,&m,&A);
    rep(i,m)scanf("%d",&b[i]);
    ans=cal_cnt(b[1]);
    rep(i,m-1)ans=1ll*ans*cal_cnt(b[i+1]-b[i])%MOD;
    ans=1ll*ans*mypow(A,n-2*b[m])%MOD;
    printf("%d\n",ans);
	return 0;
}