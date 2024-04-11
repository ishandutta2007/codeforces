#include <cstdio>
#include <algorithm>
#include <cstdlib>

int M=1000000007;

char dat[5010];
int n;

int dp[5010][5010];
int dp_prefix[5010][5010];
int differ[5010][5010];

void input(){
    scanf("%d",&n); //n=5000; 
    scanf("%s",dat+1); //for(int i=1;i<=n;++i) dat[i]=rand()%10 + 48; //
    for(int i=1;i<=n;++i) dat[i]-='0';
}

void build_diff(){
    for(int len=1;len<n;++len){
        for(int i=n-len;i>=1;--i){
            if(dat[i]==dat[i+len]) differ[i][i+len]=differ[i+1][i+len+1]+1;
            else differ[i][i+len]=0;
        }
    }
}

bool partial_compare(int a,int b,int len){
    return differ[a][b]<len && dat[a+differ[a][b]]<dat[b+differ[a][b]];
}

void work(int l,int r){
    int& ret=dp[l][r];
    if(l==1){
        ret=1; return;
    }
    if(dat[l]==0){
        ret=0; return;
    }
    ret += dp_prefix[l-1][l-1];
    int tmp = 2*l-r-1;
    if(tmp>=1){
        ret-=dp_prefix[tmp][l-1];
        ret=(ret+M)%M;
        if(partial_compare(tmp,l,r-l+1)){
            ret+=dp[tmp][l-1];
            ret%=M;
        }
    }
}

void do_dp(){
    for(int j=1;j<=n;++j){
        for(int i=1;i<=j;++i){
            work(i,j);
            dp_prefix[i][j]=(dp_prefix[i-1][j]+dp[i][j])%M;
        }
    }
}

int main()
{
    input();
    build_diff();
    do_dp();
    int ans=0;
    for(int i=1;i<=n;++i) ans=(ans+dp[i][n])%M;
    printf("%d\n",ans);
    return 0;
}