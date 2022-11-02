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

char in[101000];
int stk[101000],sc;
int cnt[101000];
int pre[101000];
int main(){
    int i;
    scanf("%s",in);
    int n=strlen(in);
    cnt[0]=0;
    for(i=0;i<n;i++)pre[i]=-1;
    for(i=1;i<=n;i++)cnt[i]=cnt[i-1]+(in[i-1]=='['?1:0);
    for(i=0;i<n;i++){
        if(in[i]=='('||in[i]=='['){
            stk[sc++]=i;
        }else{
            if(sc==0||(in[stk[sc-1]]=='('&&in[i]==']')
                    ||(in[stk[sc-1]]=='['&&in[i]==')')){
                sc=0;
                continue;
            }
            pre[i]=stk[sc-1];
            if(pre[i]>0&&pre[pre[i]-1]!=-1){
                pre[i]=pre[pre[i]-1];
            }
            sc--;
        }
    }
    int ma=0,ml=0,mr=-1;
    for(i=0;i<n;i++)if(pre[i]!=-1&&ma<cnt[i+1]-cnt[pre[i]]){
        ma=cnt[i+1]-cnt[pre[i]];
        ml=pre[i];mr=i;
    }
    printf("%d\n",ma);
    for(i=ml;i<=mr;i++)printf("%c",in[i]);
    puts("");
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread