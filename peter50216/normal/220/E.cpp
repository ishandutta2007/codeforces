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

int in[101000];
int in2[101000];
int n;
long long k;
map<int,int> xx;
int tre[101000];
int tb[101000];
int xn;
inline void add(int* tr,int x,int c=1){
    for(;x<=xn;x+=x&-x)tr[x]+=c;
}
inline int que(int* tr,int x){
    int r=0;
    for(;x;x-=x&-x)r+=tr[x];
    return r;
}
inline long long solve(){
    long long ss=0;
    int i,j;
    for(j=n-1;j>=0;j--){
        int x=que(tb,in[j]-1);
        if(ss+x>k){
            j++;
            break;
        }
        ss+=x;
        add(tb,in[j]);
    }
    if(j==-1)return n*(n-1ll)/2;
    long long ret=0;
    for(i=0;i<n;i++){
        ss+=que(tre,xn+1-in[i]-1);
        ss+=que(tb,in[i]-1);
        add(tre,xn+1-in[i]);
        for(;j<n;j++){
            if(ss<=k)break;
            ss-=que(tre,xn+1-in[j]-1);
            ss-=que(tb,in[j]-1);
            add(tb,in[j],-1);
        }
        if(j==n)break;
        ret+=n-j;
    }
    return ret;
}
int main(){
    int i,j;
    scanf("%d%I64d",&n,&k);
    for(i=0;i<n;i++){
        scanf("%d",&in[i]);
        in2[i]=in[i];
    }
    //lshua
    sort(in2,in2+n);
    xn=unique(in2,in2+n)-in2;
    for(i=0;i<xn;i++)xx[in2[i]]=i;
    for(i=0;i<n;i++)in[i]=xx[in[i]]+1;
    printf("%I64d\n",solve());
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread