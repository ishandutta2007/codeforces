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

int pre[2010];
int cnt[2010];
inline int find(int a){
    return pre[a]?pre[a]=find(pre[a]):a;
}
int main(){
    int n,i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        b+=1000;
        cnt[a]++;cnt[b]++;
        a=find(a);b=find(b);
        if(a!=b)pre[a]=b;
    }
    int c=0;
    for(i=1;i<=2000;i++)if(cnt[i]&&pre[i]==0)c++;
    printf("%d\n",c-1);
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread