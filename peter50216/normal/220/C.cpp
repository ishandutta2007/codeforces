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

int to[101000];
int dif[101000];
int ans[101000];
inline int ABS(int a){return a>0?a:-a;}
int main(){
    int n,i,j;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        int a;
        scanf("%d",&a);
        to[a]=i;
    }
    for(i=1;i<=n;i++){
        int a;
        scanf("%d",&a);
        dif[i]=to[a]-i;
        ans[i]=101000;
    }
    ans[0]=101000;
    set<int> XD;
    for(i=1;i<=n;i++){
        XD.insert(dif[i]);
        set<int>::iterator it=XD.lower_bound(n-i);
        if(it!=XD.end()){
            ans[i]=min(ans[i],ABS(*it-(n-i)));
        }
        if(it!=XD.begin()){
            it--;
            ans[i]=min(ans[i],ABS(*it-(n-i)));
        }
    }
    XD.clear();
    for(i=n;i>=1;i--){
        XD.insert(dif[i]);
        set<int>::iterator it=XD.lower_bound(-(i-1));
        if(it!=XD.end()){
            ans[i-1]=min(ans[i-1],ABS(*it+(i-1)));
        }
        if(it!=XD.begin()){
            it--;
            ans[i-1]=min(ans[i-1],ABS(*it+(i-1)));
        }
    }
    ans[0]=min(ans[0],ans[n]);
    for(i=0;i<n;i++)printf("%d\n",ans[i]);
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread