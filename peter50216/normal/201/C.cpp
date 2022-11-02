// @author peter50216
// #includes {{{
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<assert.h>
#include<stdarg.h>
#include<time.h>
#include<ctype.h>
#include<string>
#include<map>
#include<set>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;
// }}}

long long in[101000];
long long ml[101000],mr[101000];
long long so[101000];
int main(){
    int n,i,j;
    scanf("%d",&n);
    n--;
    for(i=0;i<n;i++)scanf("%I64d",&in[i]);
    ml[0]=0;
    for(i=1;i<=n;i++){
        if(in[i-1]==1)ml[i]=0;
        else ml[i]=ml[i-1]+in[i-1]/2*2;
    }
    mr[n]=0;
    for(i=n-1;i>=0;i--){
        if(in[i]==1)mr[i]=0;
        else mr[i]=mr[i+1]+in[i]/2*2;
    }
    so[0]=0;
    for(i=1;i<=n;i++)so[i]=so[i-1]+(in[i-1]-1)/2*2+1;
    long long ans=0,s=0;
    for(i=n;i>=0;i--){
        s=max(s,mr[i]+so[i]);
        long long t=s+ml[i]-so[i];
        ans=max(ans,t);
    }
    printf("%I64d\n",ans);
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread