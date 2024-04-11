#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<assert.h>
#include<stdarg.h>
#include<string>
#include<map>
#include<set>
#include<algorithm>
#include<vector>
using namespace std;
int p;
int aa[1010000];
inline void pow(long long x,long long& a,long long& b){
    // a=3^x, b=1+...+3^(x-1)
    if(x==0){
        a=1;b=0;return;
    }
    if(x==1){
        a=3%p;b=1;return;
    }
    long long c,d;
    pow(x/2,c,d);
    a=(c*c)%p;
    b=(d*(1+c))%p;
    if(x%2){
        b=(b+a)%p;
        a=(a*3)%p;
    }
}
struct XD{
    long long x[2][2];
    XD(){
        int i,j;
        for(i=0;i<2;i++)for(j=0;j<2;j++)x[i][j]=0;
    }
    XD operator*(const XD& b)const{
        int i,j,k;
        XD xx;
        for(i=0;i<2;i++)for(j=0;j<2;j++)for(k=0;k<2;k++)xx.x[i][k]=(xx.x[i][k]+x[i][j]*b.x[j][k])%p;
        return xx;
    }
};
inline void fib(long long x,long long& a,long long& b){
    XD r,c;
    r.x[0][0]=r.x[0][1]=r.x[1][0]=1;
    c.x[0][0]=c.x[1][1]=1;
    while(x){
        if(x%2)c=c*r;
        r=r*r;
        x/=2;
    }
    a=c.x[0][0];b=c.x[0][1];
}
int main(){
    int n,i;
    long long x,y;
    scanf("%d%I64d%I64d%d",&n,&x,&y,&p);
    for(i=0;i<n;i++)scanf("%d",&aa[i]);
    if(n==1){
        printf("%d\n",aa[0]%p);
        return 0;
    }
    long long s=0;
    for(i=0;i<n;i++)s=(s+aa[i])%p;
    long long t=(aa[0]+aa[n-1])%p;
    long long a,b;
    pow(x,a,b);
    long long as=((s*a-t*b)%p+p)%p;
    fib(x,a,b);
    long long at=(a*aa[n-1]+b*aa[n-2]+aa[0])%p;
    pow(y,a,b);
    printf("%d\n",((as*a-at*b)%p+p)%p);
}