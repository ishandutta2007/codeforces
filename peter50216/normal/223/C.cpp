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

int c[2010];
const int mod=(int)1e9+7;
inline int add(int a,int b){
    a+=b;
    if(a>=mod)a-=mod;
    return a;
}
inline int mul(int a,int b){
    return ((long long)a*(long long)b)%mod;
}
int in[2010];
inline int rev(long long a,long long b){
    if(a==1)return 1;
    return (((1-rev(b%a,a)*b)/a)%b+b)%b;
}
int out[2010];
int main(){
    int n,k,i,j;
    scanf("%d%d",&n,&k);
    for(i=0;i<n;i++)scanf("%d",&in[i]);
    if(k==0){
        for(i=0;i<n;i++)out[i]=in[i];
    }else{
        k--;
        c[0]=1;
        for(i=1;i<n;i++){
            c[i]=mul(mul(c[i-1],add(k,i)),rev(i,mod));
        }
        for(i=0;i<n;i++){
            out[i]=0;
            for(j=0;j<=i;j++)out[i]=add(out[i],mul(in[j],c[i-j]));
        }
    }
    for(i=0;i<n;i++){
        printf("%d%c",out[i],(i==n-1?'\n':' '));
    }

}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread