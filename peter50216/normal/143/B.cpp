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
char in[1000];
char a[1000],b[1000];
int ac,bc;
int main(){
    bool f=0;
    scanf("%s",in);
    int np=0,i,j;
    if(in[0]=='-'){
        f=1;
        np++;
    }
    while(in[np]&&in[np]!='.')a[ac++]=in[np++];
    if(in[np]=='.'){
        np++;
        while(in[np])b[bc++]=in[np++];
    }
    if(bc>2)bc=2;
    while(bc<2)b[bc++]='0';
    if(f)printf("(");
    printf("$");
    for(i=0;i<ac;i++){
        if(i&&(ac-i)%3==0)printf(",");
        printf("%c",a[i]);
    }
    printf(".%c%c",b[0],b[1]);
    if(f)printf(")");
}