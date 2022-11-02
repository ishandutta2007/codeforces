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

int out[1010000],ac;
int main(){
    int n,r;
    while(scanf("%d%d",&n,&r)!=EOF){
        if(n==1){
            if(r==1)puts("0\nT");
            else puts("IMPOSSIBLE");
            continue;
        }
        int a,b,i;
        int mi=2*n;
        int ans;
        for(i=1;i<r;i++){
            a=i;b=r;
            if(__gcd(a,b)!=1)continue;
            int c=0,r=0;
            while(a>0){
                int q=b/a;
                r+=q;
                if(a==1)c+=q-2;
                else c+=q-1;
                b%=a;
                swap(a,b);
            }
            if(r==n&&c<mi){
                mi=c;
                ans=i;
            }
        }
        if(mi==2*n)puts("IMPOSSIBLE");
        else{
            printf("%d\n",mi);
            a=ans;b=r;
            ac=0;
            while(a>0){
                int q=b/a;
                q--;
                while(q--){
                    out[ac++]=0;
                }
                out[ac++]=1;
                b%=a;
                swap(a,b);
            }
            ac--;
            out[ac-1]=1;
            printf("T");
            int q=0;
            if(ac!=n-1)while(1);
            for(i=ac-1;i>=0;i--){
                q+=out[i];
                printf(q%2?"B":"T");
            }
            puts("");
        }
    }
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread