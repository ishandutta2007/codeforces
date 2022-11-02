// @author peter50216
// #includes {{{
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<assert.h>
#include<stdarg.h>
#include<time.h>
#include<limits.h>
#include<ctype.h>
#include<string>
#include<map>
#include<set>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;
// }}}

const int mod=1000000007;
int cnt[2][2];
int ch[3][2];
inline bool ver(){
    int r=(ch[0][0]+ch[1][0]+ch[2][0])*(ch[0][1]+ch[1][1]+ch[2][1]);
    for(int i=0;i<3;i++)r+=ch[i][0]*ch[i][1];
    return r%2==0;
}
inline int add(int a,int b){
    a+=b;
    if(a>=mod)a-=mod;
    return a;
}
inline int dfs(int np){
    if(np==3){
        if(ver())return 1;
        return 0;
    }
    long long ret=0;
    for(ch[np][0]=0;ch[np][0]<=1;ch[np][0]++){  
        for(ch[np][1]=0;ch[np][1]<=1;ch[np][1]++){
            int a=ch[np][0],b=ch[np][1];
            if(cnt[a][b]==0)continue;
            long long k=cnt[a][b];
            cnt[a][b]--;
            ret=(ret+dfs(np+1)*k)%mod;
            cnt[a][b]++;
        }
    }
    return ret;
}
int gcds[4010][4010];
int cc[4010][4010];
inline int gcd(int a,int b){if(b)while((a%=b)&&(b%=a));return a+b;}
inline int solve(int w,int h){
    cnt[0][0]=((w/2+1ll)*(h/2+1ll))%mod;
    cnt[0][1]=((w/2+1ll)*((h+1ll)/2))%mod;
    cnt[1][0]=(((w+1ll)/2)*(h/2+1ll))%mod;
    cnt[1][1]=(((w+1ll)/2)*((h+1ll)/2))%mod;
    int ans=dfs(0);
    for(int i=1;i<=4000;i++){
        gcds[i][0]=i;
        for(int j=1;j<=4000;j++){
            gcds[i][j]=gcds[i][j-1]+gcd(i,j);
        }
    }
    for(int i=0;i<=4000;i++){
        cc[i][0]=0;
        for(int j=1;j<=4000;j++){
            cc[i][j]=add(cc[i][j-1],gcds[j][i]-i-1);
        }
    }
    int s=0;
    for(int i=0;i<=w;i++){
        for(int j=0;j<=h;j++){
            s=add(s,cc[h-j][w-i]);
            s=add(s,cc[w-i][j]);
        }
    }
    s=(s*6ll)%mod;
    ans-=s;
    if(ans<0)ans+=mod;
    return ans;
}
int main(){
    int w,h;
    scanf("%d%d",&w,&h);
    printf("%d\n",solve(w,h));
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread