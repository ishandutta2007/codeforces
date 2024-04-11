#include<stdio.h>
#include<algorithm>
using namespace std;
int in[100100];
int main(){
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%d",&in[i]);
    sort(in,in+n);
    printf(n==1&&in[0]==1?"2":"1");
    for(i=0;i<n-1;i++)printf(" %d",in[n-1]==1&&i==n-2?2:in[i]);
    puts("");
}