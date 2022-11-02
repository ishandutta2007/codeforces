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
int c[101000];
int main(){
    int a,b,m,r0;
    scanf("%d%d%d%d",&a,&b,&m,&r0);
    int i;
    for(i=1;;i++){
        if(c[r0]){
            printf("%d\n",i-c[r0]);
            break;
        }
        c[r0]=i;
        r0=(a*r0+b)%m;
    }
}