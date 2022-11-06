#include <cstdio>
#include <algorithm>

using namespace std;
typedef pair<int,int> pp;

int h,w,n;

pp data[2010];

long long M=1000000007;

long long dp[2010][2];

int powbase;

long long pc;

int pow(int b){
    if(b==0) return 1;
    if(b==1) return powbase;
    long long ret=pow(b>>1);
    ret=(ret*ret%M);
    if(b&1) ret=(ret*powbase%M);
    return ret;
}

int moinvmm [200010];
int factmemo[200010];

int moinv(int x){ if(moinvmm[x]) return moinvmm[x]; powbase=factmemo[x]; return moinvmm[x]=pow(M-2); }

int combi(int a,int b){
    return (((1LL*factmemo[a]*moinv(b)%M)*moinv(a-b))%M);
}

int path(int dx,int dy){
    return combi(dx+dy,dx);
}

int abs(int x) { return x>0?x:-x; }

int main()
{
    factmemo[0]=1;
    factmemo[1]=1;
    scanf("%d%d%d",&h,&w,&n);
    int i,j;
    for(i=2;i<=200000;++i) factmemo[i]=(1LL*factmemo[i-1]*i)%M;
    
    n+=2;
    
    data[1].first=1; data[1].second=1;
    
    for(i=2;i<n;++i) scanf("%d%d",&data[i].first, &data[i].second);
    
    data[n].first=h; data[n].second=w;
    
    sort(data+1,data+n+1);
    
    dp[1][0]=1;
    int tmp;
    
    for(i=2;i<=n;++i){
        for(j=1;j<i;++j){
            if(data[j].second<=data[i].second){
                dp[i][0]=(dp[i][0]+(tmp=path(data[i].second-data[j].second,data[i].first-data[j].first))*dp[j][1])%M;
                dp[i][1]=(dp[i][1]+tmp*dp[j][0])%M;
            }
        }
    }
    printf("%I64d\n",(dp[n][1]-dp[n][0]+M)%M);
    return 0;
}