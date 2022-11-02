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
char b[100];
int main(){
    long long a;
    scanf("%I64d%s",&a,&b);
    int i;
    long long bb=0;
    for(i=strlen(b)-1;i>=0;i--){
        bb=bb*10+b[i]-'0';
    }
    printf("%I64d\n",a+bb);
}