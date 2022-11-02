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
const int mod=1000000007;
struct XD{
    long long x[2][2];
    XD(){
        memset(x,0,sizeof(x));
    }
    XD operator*(const XD& b)const{
        int i,j,k;
        XD r;
        for(i=0;i<2;i++)for(j=0;j<2;j++)for(k=0;k<2;k++){
            (r.x[i][k]+=x[i][j]*b.x[j][k])%=mod;
        }
        return r;
    }
};
XD a,b;
int main(){
    long long n;
    scanf("%I64d",&n);
    a.x[0][0]=a.x[1][1]=3;
    a.x[0][1]=a.x[1][0]=1;
    b.x[0][0]=b.x[1][1]=1;
    while(n){
        if(n%2)b=b*a;
        a=a*a;
        n/=2;
    }
    printf("%d\n",(int)b.x[0][0]);
}