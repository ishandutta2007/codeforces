#include<stdio.h>
#include<algorithm>
using namespace std;
int in[100];
int main(){
    int d;
    scanf("%d",&d);
    int i;
    for(i=0;i<12;i++)scanf("%d",&in[i]);
    sort(in,in+12);
    for(i=11;i>=0;i--){
        if(d<=0)break;
        d-=in[i];
    }
    printf("%d\n",d>0?-1:11-i);
}