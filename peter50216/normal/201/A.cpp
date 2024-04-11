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
    int x,n;
    scanf("%d",&x);
    if(x==3){
        puts("5");
        return 0;
    }
    for(n=1;;n+=2){
        if((n*n+1)/2>=x){
            printf("%d\n",n);
            return 0;
        }
    }
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread