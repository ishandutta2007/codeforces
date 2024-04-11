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

int in[1010][1010];
long long sx[1010],sy[1010];
inline long long ABS(long long x){return x>0?x:-x;}
inline long long sq(long long x){return x*x;}
int main(){
    int n,m,i,j;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)for(j=0;j<m;j++){
        scanf("%d",&in[i][j]);
        sx[i]+=in[i][j];
        sy[j]+=in[i][j];
    }
    long long mi,m2;
    mi=1000000000000000000ll;
    int x,y;
    for(i=0;i<=n;i++){
        long long s=0;
        for(j=0;j<n;j++)s+=sq(j*4+2-i*4)*sx[j];
        if(s<mi){
            mi=s;x=i;
        }
    }
    m2=1000000000000000000ll;
    for(i=0;i<=m;i++){
        long long s=0;
        for(j=0;j<m;j++)s+=sq(j*4+2-i*4)*sy[j];
        if(s<m2){
            m2=s;y=i;
        }
    }
    printf("%I64d\n%d %d\n",mi+m2,x,y);
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread