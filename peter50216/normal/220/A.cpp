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
int in[100010];
int i2[101000];
int main(){
    int n,i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&in[i]);
        i2[i]=in[i];
    }
    sort(in,in+n);
    int c=0;
    for(i=0;i<n;i++){
        if(i2[i]!=in[i])c++;
    }
    puts(c<=2?"YES":"NO");
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread