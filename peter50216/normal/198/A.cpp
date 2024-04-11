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

int main(){
    long long k,b,n,t;
    scanf("%I64d%I64d%I64d%I64d",&k,&b,&n,&t);
    long long x=1,c=0;
    while(k*x+b<=t){
        c++;
        x=k*x+b;
    }
    printf("%I64d\n",max(0ll,n-c));
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread