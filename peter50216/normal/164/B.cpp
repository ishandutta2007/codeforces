#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<assert.h>
#include<stdarg.h>
#include<time.h>
#include<string>
#include<map>
#include<set>
#include<algorithm>
#include<vector>
using namespace std;
int a[1010000],b[1010000];
int uid[1010000];
int ub[1010000];
int bb[1010000];
int bp[1010000];
int que[4010000];
int main(){
    int n,m,i,j;
    scanf("%d%d",&n,&m);
    memset(uid,-1,sizeof(uid));
    memset(bp,-1,sizeof(bp));
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
        uid[a[i]]=i;
    }
    int bc=0;
    for(i=0;i<m;i++){
        scanf("%d",&b[i]);
        if(uid[b[i]]==-1)continue;
        bb[bc++]=uid[b[i]];
        bp[bb[bc-1]]=bc-1;
    }
    /*for(i=0;i<bc;i++)printf("%d ",bb[i]);
    puts("");
    for(i=0;i<n;i++)printf("%d ",bp[i]);
    puts("");*/
    if(n==1){
        if(bp[0]==-1)puts("0");
        else puts("1");
        return 0;
    }
    int ans=0,qs=0,qe=0;
    for(i=0;i<2*n;i++){
        int ii=i%n;
        //printf("i=%d ii=%d qs=%d qe=%d bp[ii]=%d\n",i,ii,qs,qe,bp[ii]);
       // for(j=qs;j<qe;j++)printf("%d ",que[j]);
       // puts("");
        if(bp[ii]==-1){
            qs=qe=0;
            continue;
        }
        que[qe++]=bp[ii];
        while(qe-qs>2){
            int a=que[qs],b=que[qe-2],c=que[qe-1];
            if((a>c&&c>b)||(c>b&&b>a)||(b>a&&a>c)){
                break;
            }else qs++;
        }
        if(qe-qs>ans)ans=qe-qs;
    }
    printf("%d\n",ans);
}