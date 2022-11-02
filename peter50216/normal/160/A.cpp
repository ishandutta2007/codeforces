#include<stdio.h>
#include<algorithm>
using namespace std;
int in[1000];
int main(){
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%d",&in[i]);
    sort(in,in+n);
    int s=0;
    for(i=0;i<n;i++)s+=in[i];
    int ss=0;
    for(i=n-1;i>=0;i--){
        if(ss*2>s)break;
        ss+=in[i];
    }
    printf("%d\n",n-1-i);
}